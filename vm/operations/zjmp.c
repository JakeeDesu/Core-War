/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:56:21 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/28 11:03:17 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	exec_zjmp(t_vm *vm, t_carriage *carr, int *args, int *types)
{
	int	address;

	address = ((carr->current_position + (args[0] % IDX_MOD)) % MEM_SIZE);
	if (carr->carry == 1)
		carr->current_position = address;
	else
		carr->current_position += 1 + jump_args(carr->op_id, types);
	if (vm->op_flag)
		show_args(carr, args[0], args[1], args[2]);
}

void	zjmp(t_vm *vm, t_carriage *carriage)
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
				exec_zjmp(vm, carriage, args, types);
		}
	}
	else
	{
		carriage->current_position += 1;
		carriage->current_position += jump_args(carriage->op_id, types);
	}
	carriage->cycles_remaining = -1;
}
