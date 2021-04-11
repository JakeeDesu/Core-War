/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <hmhindat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:57:51 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/28 11:05:49 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	exec_lfork(t_vm *vm, t_carriage *carr, int *args, int *types)
{
	t_carriage	*new_carr;

	new_carr = new_carriage(vm, carr);
	new_carr->id = vm->carr_uid + 1;
	vm->carr_uid += 1;
	new_carr->sleep = 0;
	vm->carriages->prev = new_carr;
	new_carr->next = vm->carriages;
	vm->carriages = new_carr;
	new_carr->current_position = (carr->current_position +
			args[0]) % MEM_SIZE;
	new_carr->op_id = vm->arena.mem[new_carr->current_position];
	new_carr->cycles_remaining = -1;
	if (vm->op_flag)
		show_args(carr, args[0], args[1], args[2]);
	types[0] = 0;
}

void	lfork(t_vm *vm, t_carriage *carriage)
{
	int				args[3];
	int				types[3];
	int				jump;

	ft_bzero(args, sizeof(int) * 3);
	ft_bzero(types, sizeof(int) * 3);
	if (check_arg_type(vm, types, carriage))
	{
		if ((jump = get_args(vm, args, types, carriage)))
		{
			if (check_reg_val(carriage->op_id, types, args))
				exec_lfork(vm, carriage, args, types);
			carriage->current_position += jump;
		}
	}
	else
	{
		carriage->current_position += 1;
		carriage->current_position += jump_args(carriage->op_id, types);
	}
	carriage->cycles_remaining = -1;
}
