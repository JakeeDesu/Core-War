/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:23:29 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/11 18:24:20 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	show_header(t_header header)
{
	ft_putstr("\n\t-------------------\n");
	ft_putstr("magic : ");
	ft_putnbr(header.magic);
	ft_putstr("\n");
	ft_putstr("prog_name : ");
	ft_putstr(header.prog_name);
	ft_putstr("\n");
	ft_putstr("prog_size : ");
	ft_putnbr(header.prog_size);
	ft_putstr("\n");
	ft_putstr("comment : ");
	ft_putstr(header.comment);
	ft_putstr("\n\t-------------------\n\n");
}
