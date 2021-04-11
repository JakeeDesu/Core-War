/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <hmhindat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:24:24 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/28 10:35:13 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	hex(char x)
{
	if (x <= 9 && x >= 0)
		return ('0' + x);
	else if (x == 10)
		return ('a');
	else if (x == 11)
		return ('b');
	else if (x == 12)
		return ('c');
	else if (x == 13)
		return ('d');
	else if (x == 14)
		return ('e');
	else if (x == 15)
		return ('f');
	else
	{
		ft_putstr("hex :\n\tError cant conv x to hexa\n");
		exit(0);
	}
}

char	*to_hex(void *bytes, size_t size)
{
	char			*hex_byte;
	unsigned char	*byte;
	unsigned char	hex_num;
	int				i;
	int				j;

	byte = (unsigned char*)bytes;
	hex_byte = ft_memalloc(sizeof(char) * ((size * 2) + 1));
	i = 0;
	while ((size_t)i < size)
	{
		hex_num = byte[i];
		j = (i * 2) + 1;
		while (j >= (i * 2))
		{
			hex_byte[j] = hex(hex_num - (16 * (hex_num / 16)));
			hex_num = hex_num / 16;
			j--;
		}
		i++;
	}
	return (hex_byte);
}

void	print_hex(unsigned char byte, char color)
{
	byte = ((byte & 0x0f) << 4 | (byte & 0xf0) >> 4);
	ft_putchar(hex(byte - (16 * (byte / 16))));
	byte = (byte / 16) + (color * 0);
	ft_putchar(hex(byte - (16 * (byte / 16))));
}
