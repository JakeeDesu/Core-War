/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_vis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 05:54:40 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/28 11:32:35 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	flag_vis(t_vm *vm, char **argv, int argc, int *nb)
{
	(*nb)++;
	if ((*nb) >= argc)
	{
		ft_putstr("USAGE ERROR: [-V]\n\t");
		ft_putstr(" missing arg ");
		ft_putstr(argv[*nb]);
		ft_putstr("\n");
		clean_exit(&(vm->mem));
	}
	vm->vis_flag = 1;
}
