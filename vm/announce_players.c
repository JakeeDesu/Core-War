/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   announce_players.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:21:11 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/11 13:22:33 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	announce_players(t_vm *vm)
{
	size_t	idx;

	idx = 0;
	ft_putstr("Introducing contestants...\n");
	while (idx < vm->players_nb)
	{
		ft_putstr("* Player ");
		ft_putnbr(vm->players[idx].id);
		ft_putstr(", weighing ");
		ft_putnbr(vm->players[idx].header.prog_size);
		ft_putstr(" bytes, \"");
		ft_putstr(vm->players[idx].header.prog_name);
		ft_putstr("\" (\"");
		ft_putstr(vm->players[idx].header.comment);
		ft_putstr("\") !\n");
		idx++;
	}
}
