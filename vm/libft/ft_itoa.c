/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:30:23 by iberchid          #+#    #+#             */
/*   Updated: 2018/10/10 08:02:14 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		calc(int n)
{
	int				i;
	unsigned int	m;

	i = 0;
	if (n < 0)
	{
		m = n * (-1);
		i++;
	}
	else
		m = n;
	while (m >= 10)
	{
		m = m / 10;
		i++;
	}
	i++;
	return (i);
}

int		base(int n)
{
	int i;
	int j;
	int m;

	if (n < 0)
		i = calc(n) - 1;
	else
		i = calc(n);
	j = 0;
	m = 1;
	while (j < (i - 1))
	{
		m = m * 10;
		j++;
	}
	return (m);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	m;
	unsigned int	b;
	int				i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (calc(n) + 1))))
		return (NULL);
	if (n < 0)
	{
		str[i++] = '-';
		m = n * (-1);
	}
	else
		m = n;
	b = base(m);
	while (i < calc(n))
	{
		str[i++] = (m / b) + '0';
		m = m % b;
		b = b / 10;
	}
	str[i] = '\0';
	return (str);
}
