/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:43:12 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/27 14:44:16 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_string(t_data *data, int fd, int l)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * (l + 1))))
	{
		close(fd);
		free_data(data);
		exit(0);
	}
	lseek(fd, -l, SEEK_CUR);
	read(fd, str, l);
	data->last.tok->h = l;
	str[l] = '\0';
	return (str);
}

void	is_string(t_data *data, int fd)
{
	char	c;
	int		l;

	l = 1;
	while (read(fd, &c, 1))
	{
		l++;
		(data->nt)++;
		if (c == '"')
			break ;
		if (c == '\n')
		{
			(data->nl)++;
			data->nt = 0;
		}
	}
	data->last.tok->cnt = get_string(data, fd, l);
	data->last.tok->t = 5;
}
