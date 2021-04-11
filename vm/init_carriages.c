/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_carriages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <hmhindat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:19:38 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/28 10:43:16 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_carriages(t_vm *vm)
{
	int			idx;
	size_t		champs_mem_idx_diff;
	t_carriage	*carriage;

	idx = 0;
	champs_mem_idx_diff = (size_t)(MEM_SIZE / vm->players_nb);
	while ((size_t)idx < vm->players_nb)
	{
		carriage = add_carr(vm, &(vm->carriages));
		carriage->id = vm->carr_uid + 1;
		vm->carr_uid += 1;
		carriage->carry = 0;
		carriage->current_position = (idx) * champs_mem_idx_diff;
		carriage->r[0] = -1 * (vm->players[idx].id);
		carriage->op_id = vm->arena.mem[carriage->current_position % MEM_SIZE];
		carriage->cycles_remaining = -1;
		idx++;
	}
}
