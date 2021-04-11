/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:38:09 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/28 10:57:09 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	delete_carr(t_vm *vm, t_carriage **current, t_carriage **to_be_deleted)
{
	if (!((*current)->prev) && !((*current)->next))
	{
		*current = NULL;
		vm->carriages = NULL;
	}
	else if ((*current)->prev)
	{
		(*current)->prev->next = (*current)->next;
		if ((*current)->next)
			(*current)->next->prev = (*current)->prev;
		*to_be_deleted = *current;
		*current = (*current)->next;
	}
	else if ((*current)->next)
	{
		(*current)->next->prev = NULL;
		*to_be_deleted = *current;
		*current = (*current)->next;
		vm->carriages = *current;
	}
}

void	delete_dead_carriages(t_vm *vm, int kill_all)
{
	t_carriage *current;
	t_carriage *to_be_deleted;

	current = vm->carriages;
	while (current)
	{
		if (current->dead || kill_all)
			delete_carr(vm, &current, &to_be_deleted);
		else
		{
			current->nb_of_lives = 0;
			current = current->next;
		}
	}
}

int		mark_dead_carriages(t_vm *vm)
{
	t_carriage	*carr;
	int			lives_performed;

	carr = vm->carriages;
	lives_performed = 0;
	while (carr)
	{
		lives_performed += carr->nb_of_lives;
		if (vm->cycle_to_die <= 0)
		{
			carr->dead = 1;
		}
		else if ((int)(carr->last_live_performed) >= vm->cycle_to_die)
		{
			carr->dead = 1;
		}
		carr = carr->next;
	}
	return (lives_performed);
}
