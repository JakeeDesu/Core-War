/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:57:56 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/20 05:53:57 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	flag_d(t_vm *vm, char **argv, int argc, int *nb)
{
	(*nb)++;
	if ((*nb) + 1 >= argc)
	{
		ft_putstr("USAGE ERROR: [");
		ft_putstr(argv[*nb - 1]);
		ft_putstr("]\n\t\"");
		ft_putstr("\" missing arg \n");
		clean_exit(&(vm->mem));
	}
	if (check_order_nbr(argv[(*nb)]))
	{
		vm->dump_cycle = ft_atoi(argv[(*nb)]);
		if (ft_strcmp("d", argv[*nb - 1] + 1) == 0)
			vm->dump_flag = 2;
		else
			vm->dump_flag = 1;
	}
	else
	{
		ft_putstr("USAGE ERROR: [-dump]\n\t\"");
		ft_putstr(argv[(*nb)]);
		ft_putstr("\" number not valid\n");
		clean_exit(&(vm->mem));
	}
	(*nb)++;
}
