/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <hmhindat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:15:29 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/28 10:41:17 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	show_player(t_vm *vm)
{
	t_player	*player_list;
	int			i;

	i = 0;
	player_list = vm->players;
	ft_putstr("\t---\n");
	while (i < MAX_PLAYERS)
	{
		ft_putstr("player : ");
		ft_putstr(player_list[i].header.prog_name);
		ft_putstr("\nflag_id : ");
		ft_putnbr(player_list[i].flag_id);
		ft_putstr("\nid : ");
		ft_putnbr(player_list[i].id);
		ft_putstr("\n\n");
		i++;
	}
	ft_putstr("\t---\n");
}

void	load_players(t_vm *vm)
{
	int			i;
	size_t		j;
	size_t		indx;
	size_t		distance_between_champs;

	distance_between_champs = (size_t)(MEM_SIZE / vm->players_nb);
	i = 0;
	indx = 0;
	while ((size_t)i < vm->players_nb)
	{
		j = 0;
		while (j < vm->players[i].header.prog_size)
		{
			vm->arena.mem[indx] = vm->players[i].exec_code[j];
			vm->arena.color[indx] = vm->players[i].id * -1;
			indx++;
			j++;
		}
		indx += distance_between_champs - vm->players[i].header.prog_size;
		i++;
	}
	init_carriages(vm);
	vm->alive_player_p = (vm->players)[vm->players_nb - 1].id;
}
