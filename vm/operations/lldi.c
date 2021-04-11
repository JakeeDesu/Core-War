/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:07:58 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/28 11:04:52 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	exec_lldi(t_vm *vm, t_carriage *carr, int *args, int *types)
{
	int address;
	int value1;
	int value2;

	value1 = 0;
	value2 = 0;
	if (vm->op_flag)
		show_args(carr, args[0], args[1], args[2]);
	if (types[0] == REG_CODE)
		value1 = carr->r[args[0] - 1];
	else if (types[0] == DIR_CODE)
		value1 = args[0];
	else if (types[0] == IND_CODE)
		value1 = read_mem(vm, carr->current_position +
				(args[0] % IDX_MOD), REG_SIZE);
	if (types[1] == REG_CODE)
		value2 = carr->r[args[1] - 1];
	if (types[1] == DIR_CODE)
		value2 = args[1];
	address = value1 + value2;
	carr->r[args[2] - 1] = read_mem(vm, carr->current_position +
			address, REG_SIZE);
	carr->carry = (carr->r[args[2] - 1] == 0) ? 1 : 0;
}

void	lldi(t_vm *vm, t_carriage *carriage)
{
	int				args[3];
	int				types[3];
	int				jump;

	if (check_arg_type(vm, types, carriage))
	{
		if ((jump = get_args(vm, args, types, carriage)))
		{
			if (check_reg_val(carriage->op_id, types, args))
				exec_lldi(vm, carriage, args, types);
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
