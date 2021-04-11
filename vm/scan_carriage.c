/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_carriage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 03:51:21 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/20 04:49:23 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	execute_op(t_carriage *carr, t_vm *vm)
{
	t_fun fun;

	fun = vm->op_funs[carr->op_id - 1];
	if (fun)
		fun(vm, carr);
	else
	{
		ft_putstr(" op not found : ");
		ft_putstr(g_op_tab[carr->op_id - 1].name);
		ft_putstr("\n");
		exit(0);
		carr->current_position += 1;
	}
}

void	adjust_current_posi(t_carriage *carr)
{
	if (carr->current_position < 0)
		carr->current_position = MEM_SIZE + carr->current_position;
	carr->current_position = carr->current_position % MEM_SIZE;
}

int		check_carr_op(t_vm *vm, t_carriage *carr)
{
	if (check_op_id(vm->arena.mem[carr->current_position], vm))
		return (1);
	else if (check_op_id(carr->op_id, vm) && carr->cycles_remaining > -1)
		return (1);
	return (0);
}

void	load_op(t_vm *vm, t_carriage *carr)
{
	carr->op_id = vm->arena.mem[carr->current_position];
	carr->cycles_remaining = g_op_tab[carr->op_id - 1].c_b_f;
}

char	scan_carr(t_vm *vm)
{
	t_carriage *carr;

	carr = vm->carriages;
	while (carr)
	{
		vm->current_carr = carr;
		adjust_current_posi(carr);
		(vm->arena.carr)[carr->current_position] = carr->id;
		if (check_carr_op(vm, carr))
		{
			if (carr->cycles_remaining <= -1)
				load_op(vm, carr);
			carr->cycles_remaining -= 1;
			if (carr->cycles_remaining == 0)
				execute_op(carr, vm);
		}
		else
		{
			carr->current_position += 1;
			carr->cycles_remaining = -1;
		}
		carr->last_live_performed += 1;
		carr = carr->next;
	}
	return (1);
}
