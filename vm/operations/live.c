/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:01:17 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/28 11:02:07 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		check_player_id(t_vm *vm, int id)
{
	int i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (id != 0 && vm->players[i].id == id)
			return (1);
		i++;
	}
	return (0);
}

void	search_and_add(t_vm *vm, int id)
{
	int i;

	i = 0;
	while ((size_t)i < (vm->players_nb))
	{
		if ((vm->players)[i].id == id)
		{
			vm->alive_player_p = id;
			(vm->players)[i].lives += 1;
		}
		i++;
	}
}

void	exec_live(t_vm *vm, t_carriage *carr, int *args, int *types)
{
	search_and_add(vm, -args[0]);
	carr->nb_of_lives += 1;
	carr->last_live_performed = 0;
	vm->live_op_performed += 1;
	if (vm->op_flag)
		show_args(carr, args[0], args[1], args[2]);
	types[0] = 0;
}

void	live(t_vm *vm, t_carriage *carriage)
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
				exec_live(vm, carriage, args, types);
			carriage->current_position += jump;
		}
	}
	else
	{
		carriage->current_position += 1;
		carriage->current_position += jump_args(carriage->op_id, types);
	}
	carriage->cycles_remaining = -1;
}
