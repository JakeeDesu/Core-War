/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affich_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:45:44 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/20 05:44:20 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	affich_arena(t_arena arena, int dump_flag)
{
	size_t	i;
	size_t	line_size;

	i = 0;
	line_size = (dump_flag == 1) ? (size_t)sqrt(MEM_SIZE) : 32;
	while (i < MEM_SIZE)
	{
		if (i == 0)
			print_address(line_size, i);
		if (i % line_size == 0 && i != 0)
		{
			ft_putstr("\n");
			print_address(line_size, i);
		}
		print_hex(arena.mem[i], 90);
		ft_putstr(" ");
		i++;
	}
	ft_putstr("\n");
}
