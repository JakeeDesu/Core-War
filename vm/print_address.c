/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <hmhindat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:13:19 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/18 19:01:33 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_address(size_t line, size_t i)
{
	int		idx;
	char	*hex_num;

	ft_putstr("0x");
	idx = ((MEM_SIZE / line) / 16) - 1;
	hex_num = to_hex(&i, (idx + 1) / 2);
	idx -= 1;
	while (idx >= 0)
	{
		ft_putchar(hex_num[idx]);
		ft_putchar(hex_num[idx + 1]);
		idx -= 2;
	}
	if (hex_num)
		free(hex_num);
	ft_putstr(" : ");
}
