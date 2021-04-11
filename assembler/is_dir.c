/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:12:29 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/26 18:31:07 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	dir_lab(t_data *data, int fd)
{
	char	c;

	data->last.tok->t = 9;
	while (read(fd, &c, 1))
	{
		if (!(label_chars(c, LABEL_CHARS)))
		{
			lseek(fd, -1, SEEK_CUR);
			break ;
		}
		(data->nt)++;
	}
	if (data->nt == data->last.tok->nt + 1)
		lexical_error(data, fd, data->nl, data->last.tok->nt);
	get_cnt(data, fd);
}

void	dir_num(t_data *data, int fd, int b)
{
	char	c;

	while (read(fd, &c, 1))
	{
		if (c > '9' || c < '0')
		{
			lseek(fd, -1, SEEK_CUR);
			break ;
		}
		(data->nt)++;
	}
	if (data->nt == b)
		lexical_error(data, fd, data->nl, data->last.tok->nt);
	data->last.tok->t = 7;
	get_cnt(data, fd);
}

void	is_dir(t_data *data, int fd)
{
	char	c;
	int		b;

	c = '\0';
	b = data->last.tok->nt;
	read(fd, &c, 1);
	(data->nt)++;
	if (c == LABEL_CHAR)
		dir_lab(data, fd);
	else
	{
		if (c == '-')
			b++;
		else
		{
			if (c > '9' || c < '0')
				lexical_error(data, fd, data->nl, data->last.tok->nt);
		}
		dir_num(data, fd, b);
	}
}
