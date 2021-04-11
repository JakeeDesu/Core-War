/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   posi_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 12:39:52 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/28 12:44:55 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dup_players_cp(t_vm *vm)
{
	int	i;

	i = 0;
	while (i < MAX_PLAYERS && (vm->players)[i].id != 0)
	{
		(vm->players_cp)[i].flag_id = (vm->players)[i].flag_id;
		(vm->players_cp)[i].id = (vm->players)[i].id;
		(vm->players_cp)[i].color = (vm->players)[i].color;
		(vm->players_cp)[i].header = (vm->players)[i].header;
		(vm->players_cp)[i].lives = (vm->players)[i].lives;
		(vm->players_cp)[i].exec_code = (vm->players)[i].exec_code;
		i++;
	}
	vm->players_nb = i;
}

int		next_place(t_vm *vm, int start_idx)
{
	int i;

	i = start_idx;
	while ((size_t)i < vm->players_nb)
	{
		if ((vm->players)[i].flag_id != -2)
		{
			(vm->players)[i].flag_id = -2;
			return (i);
		}
		i++;
	}
	return (-1);
}

void	posi_player(t_vm *vm)
{
	int i;
	int	idx;

	i = 0;
	idx = 0;
	while ((size_t)i < vm->players_nb)
	{
		if ((vm->players_cp)[i].flag_id == -1)
		{
			idx = next_place(vm, 0);
			(vm->players)[idx] = (vm->players_cp)[i];
			(vm->players)[idx].flag_id = -2;
		}
		vm->players[i].id = idx + 1;
		i++;
	}
}
