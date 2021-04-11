/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_carriages.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <hmhindat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:47:59 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/28 10:43:35 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		init_regs(t_carriage *new_carr, t_carriage *cp_carr)
{
	int	i;

	i = 0;
	while (i < REG_NUMBER)
	{
		if (cp_carr)
			new_carr->r[i] = cp_carr->r[i];
		else
			new_carr->r[i] = 0;
		i++;
	}
}

void		cp_values(t_carriage *new_carr, t_carriage *cp_carr)
{
	if (cp_carr)
	{
		new_carr->id = cp_carr->id;
		new_carr->op_id = 0;
		new_carr->carry = cp_carr->carry;
		new_carr->last_live_performed = cp_carr->last_live_performed + 1;
		new_carr->nb_of_lives = cp_carr->nb_of_lives;
		new_carr->cycles_remaining = -1;
		new_carr->current_position = 0;
		new_carr->to_be_crossed = -1;
		new_carr->dead = 0;
		new_carr->sleep = 0;
	}
}

t_carriage	*new_carriage(t_vm *vm, t_carriage *cp_carr)
{
	t_carriage	*new_carr;

	new_carr = mallo(&(vm->mem), sizeof(t_carriage));
	if (!cp_carr)
	{
		new_carr->id = -1;
		new_carr->op_id = 0;
		new_carr->carry = 0;
		new_carr->last_live_performed = 0;
		new_carr->nb_of_lives = 0;
		new_carr->cycles_remaining = -1;
		new_carr->current_position = 0;
		new_carr->to_be_crossed = -1;
		new_carr->sleep = 0;
		new_carr->dead = 0;
	}
	else
		cp_values(new_carr, cp_carr);
	init_regs(new_carr, cp_carr);
	new_carr->next = NULL;
	new_carr->prev = NULL;
	return (new_carr);
}

t_carriage	*add_carr(t_vm *vm, t_carriage **carriage)
{
	t_carriage	*new_carr;

	new_carr = NULL;
	if (carriage)
	{
		new_carr = new_carriage(vm, NULL);
		new_carr->next = NULL;
		if (*carriage)
		{
			(*carriage)->prev = new_carr;
			new_carr->next = *carriage;
			*carriage = new_carr;
		}
		else
			*carriage = new_carr;
	}
	return (new_carr);
}
