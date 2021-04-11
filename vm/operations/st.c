/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:17:03 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/20 03:43:39 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	exec_st(t_vm *vm, t_carriage *carr, int *args, int *types)
{
	int	address;
	int	value;

	if (vm->op_flag)
		show_args(carr, args[0], args[1], args[2]);
	value = (carr->r)[args[0] - 1];
	if (types[1] == REG_CODE)
		(carr->r)[args[1] - 1] = value;
	else if (types[1] == IND_CODE)
	{
		address = (carr->current_position + (args[1] % IDX_MOD)) % MEM_SIZE;
		write_mem(vm, address, &value, REG_SIZE);
	}
}

void	st(t_vm *vm, t_carriage *carriage)
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
				exec_st(vm, carriage, args, types);
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
