/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:36:04 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/20 04:19:28 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int	jump_args(int op_id, int *types)
{
	int args_nb;
	int jump;
	int i;

	args_nb = g_op_tab[op_id - 1].arg_num;
	jump = 0;
	i = 0;
	while (i < args_nb)
	{
		jump += type_size(types[i], g_op_tab[op_id - 1].t_dir_size);
		i++;
	}
	return (jump);
}

int	check_reg_val(int op_id, int *types, int *args)
{
	int i;
	int args_nb;

	i = 0;
	args_nb = g_op_tab[op_id - 1].arg_num;
	while (i < args_nb)
	{
		if (g_op_tab[op_id - 1].is_arg_there)
		{
			if ((types[i] == REG_CODE) && (args[i] < 1 || args[i] > 16))
				return (0);
		}
		else
		{
			if (g_op_tab[op_id - 1].args_type[i] == T_REG)
			{
				if (args[i] < 1 || args[i] > 16)
					return (0);
			}
		}
		i++;
	}
	return (1);
}

int	type_size(int type, int t_dir_size)
{
	if (type == REG_CODE)
		return (T_REG);
	if (type == IND_CODE)
		return (2);
	if (type == DIR_CODE)
	{
		if (!t_dir_size)
			return (4);
		return (T_DIR);
	}
	return (0);
}
