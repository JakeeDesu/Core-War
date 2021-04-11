/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_order.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:48:24 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/28 12:45:47 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_err(t_vm *vm, int err_id)
{
	if (err_id == 0)
	{
		ft_putstr("USAGE ERROR: [-n]\n\t");
		ft_putstr("-n [nb] player1 -n [nb] player2 ... \n");
	}
	else if (err_id == 1)
		ft_putstr("USAGE ERROR: [-n]\n\tnumbers error ... \n");
	clean_exit(&(vm->mem));
}

int		get_right_player(t_player *players, int idx)
{
	int	i;

	i = 0;
	while (i < MAX_PLAYERS && players[i].id != 0)
	{
		if (players[i].flag_id == idx)
		{
			players[i].flag_id = -2;
			return (i);
		}
		i++;
	}
	return (-1);
}

void	init_and_fill_id(t_vm *vm, int *i, int *sum, int *check_sum)
{
	*i = 0;
	*sum = 0;
	*check_sum = 0;
	while ((size_t)(*i) < vm->players_nb)
	{
		(vm->players)[*i].id = *i + 1;
		(*i)++;
	}
	*i = 0;
}

void	check_n_args(t_vm *vm)
{
	int i;
	int sum;
	int check_sum;

	if (vm->n_flag)
	{
		init_and_fill_id(vm, &i, &sum, &check_sum);
		while ((size_t)i < vm->players_nb)
		{
			if ((vm->players)[i].flag_id != -2)
				print_err(vm, 0);
			else
				sum += (vm->players)[i].id;
			check_sum += (i + 1);
			i++;
		}
		if (sum != check_sum)
			print_err(vm, 1);
	}
}

void	fix_order(t_vm *vm)
{
	t_player	p_player;
	int			i;
	int			idx;

	i = 0;
	dup_players_cp(vm);
	if (vm->n_flag)
	{
		while (i < MAX_PLAYERS && vm->players[i].id != 0)
		{
			p_player = vm->players[i];
			if ((idx = get_right_player(vm->players, i + 1)) >= 0)
			{
				vm->players[i] = vm->players[idx];
				if (i != idx)
					vm->players[idx] = p_player;
				vm->players[i].id = i + 1;
			}
			i++;
		}
		posi_player(vm);
	}
	check_n_args(vm);
}
