/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:46:35 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/11 16:47:38 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_order_nbr(char *str)
{
	char	*p_str;

	p_str = str;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	if (ft_strlen(p_str) == 10 && strcmp("2147483647", p_str) < 0)
		return (0);
	return (1);
}
