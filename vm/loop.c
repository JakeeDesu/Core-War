/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:20:47 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/28 12:49:41 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	announce_winner(t_vm *vm)
{
	t_player	*player;
	int			i;

	player = vm->players;
	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (player[i].id == (int)(vm->alive_player_p))
		{
			ft_putstr("Contestant ");
			ft_putnbr(player[i].id);
			ft_putstr(", \"");
			ft_putstr(player[i].header.prog_name);
			ft_putstr("\", has won !\n");
			break ;
		}
		i++;
	}
}

void	show_cycle(t_vm *vm)
{
	ft_putstr("It is now cycle ");
	ft_putnbr(vm->number_of_cycles);
	ft_putstr("\n");
}

void	check_vis(t_vm *vm)
{
	getmaxyx(stdscr, vm->v_data.max_y, vm->v_data.max_x);
	if (vm->v_data.max_x < 280 || vm->v_data.max_y < 70)
	{
		ft_putstr("ERROR : \n\tcould not execute successfuly");
		ft_putstr("(needs bigger window)\n");
		clean_exit(&(vm->mem));
	}
}

void	init_vis(t_vm *vm)
{
	vm->v_data.height = 68;
	vm->v_data.width = 199;
	vm->v_data.start_y = 0;
	vm->v_data.start_x = 0;
	if (vm->vis_flag)
	{
		initscr();
		check_vis(vm);
		cbreak();
		noecho();
		vm->v_data.win = newwin(vm->v_data.height, vm->v_data.width,
				vm->v_data.start_y, vm->v_data.start_x);
		refresh();
		box(vm->v_data.win, 0, 0);
		mvwprintw(vm->v_data.win, 0, 92, "   ARENA   ");
	}
}

void	loop(t_vm *vm)
{
	init_vis(vm);
	vm->number_of_cycles = 0;
	vm->cycle = 0;
	while (vm->carriages && (vm->cycle_to_die) > 0)
	{
		if (vm->dump_flag && vm->number_of_cycles == (size_t)(vm->dump_cycle))
		{
			affich_arena(vm->arena, vm->dump_flag);
			clean_exit(&(vm->mem));
		}
		scan_carr(vm);
		(vm->number_of_cycles)++;
		(vm->cycle)++;
		(vm->vis_flag == 1) ? check_vis(vm) : NULL;
		(vm->vis_flag == 1) ? draw_arena(vm, vm->v_data.win) : NULL;
		if ((vm->v_flag == 2 || vm->v_flag == 6) && !(vm->vis_flag))
			show_cycle(vm);
		if (vm->cycle == vm->cycle_to_die)
			check_carriages(vm, 0);
	}
	(vm->vis_flag == 1) ? print_winner_screen(vm) : announce_winner(vm);
}
