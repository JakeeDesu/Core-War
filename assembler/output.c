/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:02:55 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/27 18:09:14 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	byte_char(int fd, char *str, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		write(fd, str + i, 1);
		i++;
	}
}

void	to_big_endian(int fd, int i, int size)
{
	char	c;
	int		j;

	j = 1;
	while (j <= size)
	{
		c = i >> (size - j) * 8;
		write(fd, &c, 1);
		j++;
	}
}

void	to_byte_data(t_data *data, int fd)
{
	t_line	*line;
	int		i;

	line = data->lst;
	while (line)
	{
		if (line->instr)
		{
			write(fd, &(line->op), 1);
			if (line->type)
				write(fd, &(line->type), 1);
			i = 0;
			while (i < line->p)
			{
				to_big_endian(fd, line->arg[i]->val, line->arg[i]->size);
				i++;
			}
		}
		line = line->next;
	}
}

void	to_byecode(t_data *data)
{
	int		fd;
	int		null;

	null = 0;
	if ((fd = open(data->file, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
	{
		free_data(data);
		exit(0);
	}
	to_big_endian(fd, data->header.magic, 4);
	byte_char(fd, data->header.prog_name, PROG_NAME_LENGTH);
	write(fd, &null, 4);
	to_big_endian(fd, data->header.prog_size, 4);
	byte_char(fd, data->header.comment, COMMENT_LENGTH);
	write(fd, &null, 4);
	to_byte_data(data, fd);
	close(fd);
}
