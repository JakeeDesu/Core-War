/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:28:09 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/20 04:17:30 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

unsigned char	code_to_type(unsigned char code)
{
	if (code == REG_CODE)
		return (T_REG);
	else if (code == DIR_CODE)
		return (T_DIR);
	else if (code == IND_CODE)
		return (T_IND);
	return (0);
}

int				valid_types(unsigned char op, unsigned char arg_t, int *t)
{
	int				arg_nb;
	unsigned char	arg_type[4];

	arg_type[0] = (arg_t & 0xc0) >> 6;
	t[0] = arg_type[0];
	arg_type[1] = (arg_t & 0x30) >> 4;
	t[1] = arg_type[1];
	arg_type[2] = (arg_t & 0x0c) >> 2;
	t[2] = arg_type[2];
	arg_type[3] = arg_t & 0x03;
	t[3] = arg_type[3];
	arg_nb = 0;
	while (arg_nb < g_op_tab[op - 1].arg_num)
	{
		if (code_to_type(arg_type[arg_nb]) == 0)
			return (0);
		if (!((g_op_tab[op - 1].args_type[arg_nb] &
						code_to_type(arg_type[arg_nb])) ==
					code_to_type(arg_type[arg_nb])))
			return (0);
		arg_nb++;
	}
	return (1);
}

int				check_arg_type(t_vm *vm, int *types, t_carriage *carr)
{
	unsigned char	arg_type;

	arg_type = vm->arena.mem[(carr->current_position + 1) % MEM_SIZE];
	if (g_op_tab[carr->op_id - 1].is_arg_there)
	{
		if (valid_types(carr->op_id, arg_type, types))
			return (1);
		else
			return (0);
	}
	return (1);
}
