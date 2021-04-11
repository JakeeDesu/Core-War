/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:05:25 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/20 04:18:54 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int	read_arg(t_vm *vm, int arg_nb, unsigned char *type, t_carriage *carr)
{
	int		value_size;
	int		cursor;
	int		i;

	cursor = carr->current_position;
	cursor += 1;
	if (g_op_tab[carr->op_id - 1].is_arg_there)
		cursor += 1;
	i = 0;
	while (i < arg_nb)
	{
		if (carr->op_id == 12 && type[i] == IND_CODE)
			cursor += 2;
		else
			cursor += type_size(type[i], g_op_tab[carr->op_id - 1].t_dir_size);
		i++;
	}
	value_size = type_size(type[arg_nb], g_op_tab[carr->op_id - 1].t_dir_size);
	return (read_mem(vm, correct_addr(cursor), value_size));
}
