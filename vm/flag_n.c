/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:59:29 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/20 05:19:20 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	err_msg(t_vm *vm, int id, char **argv, int *nb)
{
	if (id == 0)
	{
		ft_putstr("USAGE ERROR: [-n]\n\t\"");
		ft_putstr("\" missing arg \n");
		clean_exit(&(vm->mem));
	}
	else if (id == 1)
	{
		ft_putstr("USAGE ERROR: [-n]\n\t\"");
		ft_putstr(argv[(*nb)]);
		ft_putstr("\" not a valid number\n");
		clean_exit(&(vm->mem));
	}
	else if (id == 2)
	{
		ft_putstr("USAGE ERROR: [-n]\n\t\"");
		ft_putstr(argv[(*nb)]);
		ft_putstr("\" not a valid number \n");
		clean_exit(&(vm->mem));
	}
}

int		flag_n(t_vm *vm, char **argv, int argc, int *nb)
{
	int order_id;

	order_id = -1;
	(*nb)++;
	if ((*nb) + 1 >= argc)
		err_msg(vm, 0, argv, nb);
	if (check_order_nbr(argv[(*nb)]))
	{
		order_id = ft_atoi(argv[(*nb)]);
		vm->n_flag = 1;
		if (order_id > MAX_PLAYERS || order_id <= 0)
			err_msg(vm, 1, argv, nb);
	}
	else
		err_msg(vm, 2, argv, nb);
	(*nb)++;
	return (order_id);
}
