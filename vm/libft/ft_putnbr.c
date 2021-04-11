/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:16:04 by iberchid          #+#    #+#             */
/*   Updated: 2018/10/10 18:23:08 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putc(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	m;

	if (n < 0)
	{
		ft_putc('-');
		m = n * (-1);
	}
	else
		m = n;
	if (m < 10)
		ft_putc(m + '0');
	if (m >= 10)
	{
		ft_putnbr(m / 10);
		ft_putc((m % 10) + '0');
	}
}
