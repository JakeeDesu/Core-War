/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:33:57 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/28 11:06:26 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	exec_aff(t_vm *vm, t_carriage *carr, int *args, int *types)
{
	unsigned char	value;

	if (vm->op_flag)
		show_args(carr, args[0], args[1], args[2]);
	value = (unsigned char)((carr->r)[args[0] - 1]);
	if (value != 0 && vm->a && vm->dump_flag == 0)
		ft_putchar(value);
	types[0] = 0;
}

void	aff(t_vm *vm, t_carriage *carriage)
{
	int				args[3];
	int				types[3];
	int				jump;

	if (check_arg_type(vm, types, carriage))
	{
		if ((jump = get_args(vm, args, types, carriage)))
		{
			if (check_reg_val(carriage->op_id, types, args))
				exec_aff(vm, carriage, args, types);
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
