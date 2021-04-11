/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:41:44 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/11 16:46:16 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_header(t_header *header)
{
	unsigned int	core_magic;

	core_magic = COREWAR_EXEC_MAGIC;
	if (header)
	{
		if (header->magic != COREWAR_EXEC_MAGIC)
		{
			ft_putstr("ERROR:\n\texec magic not identical\n");
			exit(0);
		}
		if (header->prog_size > CHAMP_MAX_SIZE)
		{
			ft_putstr("ERROR:\n\tprog size\n");
			exit(0);
		}
	}
}
