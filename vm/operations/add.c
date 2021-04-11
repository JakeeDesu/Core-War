/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:31:42 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/28 11:04:05 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	exec_add(t_vm *vm, t_carriage *carr, int *args, int *types)
{
	int value;

	value = carr->r[args[0] - 1] + carr->r[args[1] - 1];
	carr->r[args[2] - 1] = value;
	if (value == 0)
		carr->carry = 1;
	else
		carr->carry = 0;
	if (vm->op_flag)
		show_args(carr, args[0], args[1], args[2]);
	types[0] = 0;
}

void	add(t_vm *vm, t_carriage *carriage)
{
	int				args[3];
	int				types[3];
	int				jump;

	if (check_arg_type(vm, types, carriage))
	{
		if ((jump = get_args(vm, args, types, carriage)))
		{
			if (check_reg_val(carriage->op_id, types, args))
				exec_add(vm, carriage, args, types);
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
