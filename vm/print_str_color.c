/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:16:13 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/11 17:17:04 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_str_color(char color_id)
{
	if (color_id == 0)
		ft_putstr(RESET);
	if (color_id == 1)
		ft_putstr(RED);
	if (color_id == 2)
		ft_putstr(GREEN);
	if (color_id == 3)
		ft_putstr(YELLOW);
	if (color_id == 4)
		ft_putstr(BLUE);
	if (color_id == 5)
		ft_putstr(MAGENTA);
	if (color_id == 6)
		ft_putstr(CYAN);
}
