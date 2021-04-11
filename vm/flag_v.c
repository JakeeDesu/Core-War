/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 00:01:26 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/20 06:20:03 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_err(t_vm *vm, char **argv, int nb, int err_id)
{
	if (err_id == 0)
	{
		ft_putstr("USAGE ERROR: [-v]\n\t\"");
		ft_putstr("\" missing arg \n");
	}
	else if (err_id == 1)
	{
		ft_putstr("USAGE ERROR: [-v]\n\t\"");
		ft_putstr(argv[(nb)]);
		ft_putstr("\" not valid\n");
	}
	else if (err_id == 2)
	{
		ft_putstr("USAGE ERROR: [-v]\n\t");
		ft_putstr("number not valid\n");
	}
	clean_exit(&(vm->mem));
}

void		flag_v(t_vm *vm, char **argv, int argc, int *nb)
{
	(*nb)++;
	if ((*nb) + 1 >= argc)
		print_err(vm, argv, *nb, 0);
	if (check_order_nbr(argv[(*nb)]))
		vm->v_flag = ft_atoi(argv[(*nb)]);
	else
		print_err(vm, argv, *nb, 1);
	if (vm->v_flag != 2 && vm->v_flag != 4 && vm->v_flag != 6)
		print_err(vm, argv, *nb, 2);
	(*nb)++;
}
