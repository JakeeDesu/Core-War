/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:21:02 by iberchid          #+#    #+#             */
/*   Updated: 2018/10/09 19:43:42 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	m;

	if (n < 0)
	{
		ft_put('-', fd);
		m = n * (-1);
	}
	else
		m = n;
	if (m < 10)
		ft_put(m + '0', fd);
	if (m >= 10)
	{
		ft_putnbr_fd(m / 10, fd);
		ft_put((m % 10) + '0', fd);
	}
}
