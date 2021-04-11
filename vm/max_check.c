/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <hmhindat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:15:46 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/28 10:43:53 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_live_players(t_vm *vm)
{
	int		i;

	i = 0;
	while ((size_t)i < vm->players_nb)
	{
		(vm->players)[i].lives = 0;
		i++;
	}
}

void	show_current_cycle(t_vm *vm)
{
	if ((vm->v_flag == 2 || vm->v_flag == 6) && !(vm->vis_flag))
	{
		ft_putstr("Cycle to die is now ");
		ft_putnbr(vm->cycle_to_die);
		ft_putstr("\n");
	}
}

void	prepare_for_check(t_vm *vm, int *lives_performed, int kill_all)
{
	*lives_performed = mark_dead_carriages(vm);
	delete_dead_carriages(vm, kill_all);
}

void	init_params(t_vm *vm)
{
	vm->player_max_live = 0;
	vm->live_op_performed = 0;
	vm->cycle = 0;
	init_live_players(vm);
}

void	check_carriages(t_vm *vm, int kill_all)
{
	t_carriage	*carr;
	int			cycle_to_die_changed;
	int			lives_performed;

	carr = vm->carriages;
	cycle_to_die_changed = 0;
	prepare_for_check(vm, &lives_performed, kill_all);
	if (lives_performed >= NBR_LIVE)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->number_of_checks = 0;
		show_current_cycle(vm);
	}
	else
	{
		vm->number_of_checks += 1;
		if (vm->number_of_checks >= MAX_CHECKS)
		{
			vm->cycle_to_die -= CYCLE_DELTA;
			vm->number_of_checks = 0;
			show_current_cycle(vm);
		}
	}
	init_params(vm);
}
