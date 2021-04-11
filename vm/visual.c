/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <hmhindat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 23:48:13 by ielmoudn          #+#    #+#             */
/*   Updated: 2021/01/27 18:34:34 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_vis_data(t_vm *vm, int *i, int *j, char **hex)
{
	*i = 0;
	*j = 4;
	*hex = NULL;
	vm->v_data.w_height = 30;
	vm->v_data.w_width = 100;
	vm->v_data.w_start_y = 18;
	vm->v_data.w_start_x = 40;
	vm->v_data.winner = newwin(vm->v_data.w_height, vm->v_data.w_width,
		vm->v_data.w_start_y, vm->v_data.w_start_x);
	vm->v_data.m_height = 40;
	vm->v_data.m_width = 50;
	vm->v_data.m_start_y = 0;
	vm->v_data.m_start_x = 210;
	vm->v_data.menu = newwin(vm->v_data.m_height, vm->v_data.m_width,
	vm->v_data.m_start_y, vm->v_data.m_start_x);
	start_color();
	init_pair(0, COLOR_BLACK, COLOR_GREEN);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
}

void	print_winner_screen(t_vm *vm)
{
	t_player	*player;
	int			i;

	player = vm->players;
	i = 0;
	while (i < MAX_PLAYERS && player[i].id != (int)(vm->alive_player_p))
		i++;
	i = (i == MAX_PLAYERS) ? 0 : i;
	init_pair(2, COLOR_RED, COLOR_BLACK);
	box(vm->v_data.winner, 0, 0);
	mvwprintw(vm->v_data.winner, 0, 44, "   WINNER   ");
	mvwprintw(vm->v_data.winner, 14, 10, "The winner is : player %d %s",
		vm->players[i].id, vm->players[i].header.prog_name);
	wrefresh(vm->v_data.winner);
	getch();
}

void	print_menu(t_vm *vm)
{
	int		i;
	int		total_lives;

	i = 0;
	total_lives = 0;
	box(vm->v_data.menu, 0, 0);
	mvwprintw(vm->v_data.menu, 0, 20, "   STATUS   ");
	while ((size_t)i < vm->players_nb)
	{
		total_lives += vm->players[i].lives;
		mvwprintw(vm->v_data.menu, 2 + (3 * i), 3, "Lives for Player %d: %d",
			vm->players[i].id, vm->players[i].lives);
		i++;
	}
	mvwprintw(vm->v_data.menu, 2 + (3 * i++), 3, "Total Cycles: %d",
		vm->number_of_cycles);
	mvwprintw(vm->v_data.menu, 2 + (3 * i++), 3, "Cycle To Die: %d/%d",
		vm->cycle, vm->cycle_to_die);
	mvwprintw(vm->v_data.menu, 2 + (3 * i), 3, "Total number of lives: %d",
		total_lives);
	wrefresh(vm->v_data.menu);
}

void	wattr_on_off(t_vm *vm, int i, int on_off)
{
	if (on_off == 1 && vm->arena.color[i] == -1)
		wattron(vm->v_data.win, COLOR_PAIR(1));
	else if (on_off == 1 && vm->arena.color[i] == -2)
		wattron(vm->v_data.win, COLOR_PAIR(2));
	else if (on_off == 1 && vm->arena.color[i] == -3)
		wattron(vm->v_data.win, COLOR_PAIR(3));
	else if (on_off == 1 && vm->arena.color[i] == -4)
		wattron(vm->v_data.win, COLOR_PAIR(4));
	if (on_off == 1 && vm->arena.carr[i] != 0)
		wattron(vm->v_data.win, A_REVERSE);
	if (on_off == 1)
		return ;
	wattroff(vm->v_data.win, COLOR_PAIR(0));
	wattroff(vm->v_data.win, COLOR_PAIR(1));
	wattroff(vm->v_data.win, COLOR_PAIR(2));
	wattroff(vm->v_data.win, COLOR_PAIR(3));
	wattroff(vm->v_data.win, COLOR_PAIR(4));
	wattroff(vm->v_data.win, A_REVERSE);
}

void	draw_arena(t_vm *vm, WINDOW *win)
{
	int		i_j[2];
	char	*hex;

	init_vis_data(vm, i_j, i_j + 1, &hex);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	while (i_j[0] < MEM_SIZE)
	{
		wattr_on_off(vm, i_j[0], 1);
		hex = to_hex((void*)(&(vm->arena.mem[i_j[0]])), 1);
		mvwprintw(win, (i_j[0] / 64) + 2, i_j[1], hex, 1);
		i_j[1] += 3;
		vm->arena.carr[i_j[0]] = 0;
		i_j[0]++;
		if (i_j[0] % 64 == 0)
			i_j[1] = 4;
		wattr_on_off(vm, i_j[0], 0);
		free(hex);
		hex = NULL;
	}
	wrefresh(win);
	print_menu(vm);
	refresh();
}
