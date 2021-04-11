/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:26:22 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/27 10:27:18 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_char(char c)
{
	write(1, &c, 1);
}

void	print_str(char *str)
{
	if (str)
	{
		while (*str)
		{
			write(1, str, 1);
			str++;
		}
	}
}

void	print_nbr(int i)
{
	int	j;
	int	l;
	int	p;

	l = 1;
	j = i;
	p = 1;
	if (i < 0)
	{
		print_char('-');
		i = i * -1;
	}
	while ((j = j / 10))
	{
		l++;
		p = p * 10;
	}
	while (p)
	{
		print_char(i / p + '0');
		i = i % p;
		p = p / 10;
	}
}

void	tok_num(int i)
{
	if (i < 100)
		print_char('0');
	if (i < 10)
		print_char('0');
	print_nbr(i);
}
