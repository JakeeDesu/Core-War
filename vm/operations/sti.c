/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <hmhindat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:19:14 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/20 04:51:37 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	proc_id(t_carriage *carr)
{
	ft_putstr("p (");
	ft_putnbr(carr->id);
	ft_putstr(")  ");
}

void	show_args(t_carriage *carr, int val1, int val2, int val3)
{
	proc_id(carr);
	ft_putstr("op : ");
	ft_putstr(g_op_tab[carr->op_id - 1].name);
	ft_putstr("\targs ->  ");
	ft_putnbr(val1);
	ft_putstr(" ");
	ft_putnbr(val2);
	ft_putstr(" ");
	ft_putnbr(val3);
	ft_putstr("\tcurrent ->  ");
	ft_putnbr(carr->current_position);
	ft_putstr("\n");
}

void	show_reg(t_carriage *carr)
{
	int i;

	i = 0;
	while (i < 16)
	{
		ft_putstr(" r");
		ft_putnbr(i + 1);
		ft_putstr(" : ");
		ft_putnbr((carr->r)[i]);
		ft_putstr(" , ");
		i++;
	}
	ft_putstr("\n");
}

void	exec_sti(t_vm *vm, t_carriage *carr, int *args, int *types)
{
	int address;
	int value;
	int value1;
	int value2;

	value = (carr->r)[args[0] - 1];
	if (types[1] == DIR_CODE)
		value1 = args[1];
	else if (types[1] == REG_CODE)
		value1 = (carr->r)[args[1] - 1];
	else
		value1 = read_mem(vm, (carr->current_position +
					(args[1] % IDX_MOD)) % MEM_SIZE, REG_SIZE);
	if (types[2] == DIR_CODE)
		value2 = args[2];
	else if (types[2] == REG_CODE)
		value2 = (carr->r)[args[2] - 1];
	else
		value2 = read_mem(vm, (carr->current_position +
					(args[2] % IDX_MOD)) % MEM_SIZE, REG_SIZE);
	address = (carr->current_position + ((value1 +
					value2) % IDX_MOD)) % MEM_SIZE;
	write_mem(vm, address, &value, REG_SIZE);
	if (vm->op_flag)
		show_args(carr, args[0], args[1], args[2]);
}

void	sti(t_vm *vm, t_carriage *carriage)
{
	int args[3];
	int types[3];
	int jump;

	ft_bzero(args, sizeof(int) * 3);
	ft_bzero(types, sizeof(int) * 3);
	if (check_arg_type(vm, types, carriage))
	{
		if ((jump = get_args(vm, args, types, carriage)))
		{
			if (check_reg_val(carriage->op_id, types, args))
				exec_sti(vm, carriage, args, types);
			carriage->current_position += jump;
		}
	}
	else
	{
		carriage->current_position += 1 + 1;
		carriage->current_position += jump_args(carriage->op_id, types);
	}
	carriage->cycles_remaining = -1;
}
