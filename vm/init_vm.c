/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <hmhindat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:53:30 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/28 12:49:17 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_op(t_vm *vm)
{
	vm->op_funs[0] = &live;
	vm->op_funs[1] = &ld;
	vm->op_funs[2] = &st;
	vm->op_funs[3] = &add;
	vm->op_funs[4] = &sub;
	vm->op_funs[5] = &and;
	vm->op_funs[6] = &or;
	vm->op_funs[7] = &xor;
	vm->op_funs[8] = &zjmp;
	vm->op_funs[9] = &ldi;
	vm->op_funs[10] = &sti;
	vm->op_funs[11] = &op_fork;
	vm->op_funs[12] = &lld;
	vm->op_funs[13] = &lldi;
	vm->op_funs[14] = &lfork;
	vm->op_funs[15] = &aff;
}

void	init_players(t_vm *vm)
{
	size_t	i;

	vm->players = mallo(&(vm->mem), sizeof(t_player) * MAX_PLAYERS);
	i = 0;
	while (i < MAX_PLAYERS)
	{
		(vm->players)[i].flag_id = -1;
		(vm->players)[i].id = 0;
		(vm->players)[i].color = 0;
		(vm->players)[i].exec_code = NULL;
		(vm->players)[i].lives = 0;
		i++;
	}
	init_op(vm);
}

void	init_players_cp(t_vm *vm)
{
	size_t	i;

	vm->players_cp = mallo(&(vm->mem), sizeof(t_player) * MAX_PLAYERS);
	i = 0;
	while (i < MAX_PLAYERS)
	{
		(vm->players_cp)[i].flag_id = -1;
		(vm->players_cp)[i].id = 0;
		(vm->players_cp)[i].color = 0;
		(vm->players_cp)[i].exec_code = NULL;
		(vm->players_cp)[i].lives = 0;
		i++;
	}
}

void	init_flags(t_vm *vm)
{
	vm->n_flag = 0;
	vm->dump_flag = 0;
	vm->dump_cycle = 0;
	vm->v_flag = 0;
	vm->vis_flag = 0;
	vm->a = 0;
	vm->op_flag = 0;
}

t_vm	*init_vm(void)
{
	t_vm	*vm;
	t_list	*mem;

	mem = NULL;
	vm = mallo(&mem, sizeof(t_vm));
	init_flags(vm);
	vm->alive_player_p = 1;
	vm->player_max_live = 0;
	vm->number_of_cycles = 0;
	vm->cycle = 0;
	vm->live_op_performed = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->number_of_checks = 0;
	vm->carr_uid = 0;
	vm->carriages = NULL;
	vm->mem = mem;
	vm->current_carr = NULL;
	init_players(vm);
	init_players_cp(vm);
	return (vm);
}
