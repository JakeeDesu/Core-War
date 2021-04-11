/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:59:54 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/20 04:18:25 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	shift_and_cp(unsigned char arg_types, unsigned char *t1, int *t2)
{
	t1[0] = (arg_types & 0xc0) >> 6;
	t2[0] = t1[0];
	t1[1] = (arg_types & 0x30) >> 4;
	t2[1] = t1[1];
	t1[2] = (arg_types & 0x0c) >> 2;
	t2[2] = t1[2];
}

void	load_arg_codes(t_carriage *carr, unsigned char *type)
{
	int	i;

	i = 0;
	while (i < g_op_tab[carr->op_id - 1].arg_num)
	{
		if ((g_op_tab[carr->op_id - 1].args_type[i] & T_REG) == T_REG)
			type[i] = 1;
		else if ((g_op_tab[carr->op_id - 1].args_type[i] & T_DIR) == T_DIR)
			type[i] = 2;
		else if ((g_op_tab[carr->op_id - 1].args_type[i] & T_IND) == T_IND)
			type[i] = 3;
		i++;
	}
}

int		get_args(t_vm *vm, int *args, int *types, t_carriage *carr)
{
	int				jump;
	int				i;
	unsigned char	arg_types;
	unsigned char	type[3];

	arg_types = vm->arena.mem[(carr->current_position + 1) % MEM_SIZE];
	shift_and_cp(arg_types, type, types);
	jump = 0;
	jump += 1;
	if (g_op_tab[carr->op_id - 1].is_arg_there)
		jump += 1;
	else
		load_arg_codes(carr, type);
	i = 0;
	while (i < g_op_tab[carr->op_id - 1].arg_num)
	{
		types[i] = type[i];
		jump += type_size(type[i], g_op_tab[carr->op_id - 1].t_dir_size);
		args[i] = read_arg(vm, i, type, carr);
		i++;
	}
	return (jump);
}
