/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:36:21 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/27 11:16:45 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		read_comment(int fd)
{
	char	c;

	while (read(fd, &c, 1))
	{
		if (c == '\n')
			return (1);
	}
	return (0);
}

int		read_line(t_data *data, int fd)
{
	char	c;

	data->tlst = NULL;
	while (read(fd, &c, 1))
	{
		(data->nt)++;
		if (c != ' ' && c != '\t')
		{
			if (c == '\n')
				return (1);
			else if (c == COMMENT_CHAR || c == ALT_COMMENT_CHAR)
				return (read_comment(fd));
			else
				read_token(data, fd, c);
		}
	}
	return (0);
}

t_line	*new_line(t_data *data, int e, int fd, int l)
{
	t_line	*line;

	if (!(line = malloc(sizeof(t_line))))
	{
		free_data(data);
		close(fd);
		exit(0);
	}
	line->lst = data->tlst;
	line->e = e;
	line->p = 0;
	line->nl = l;
	line->nt = data->nt;
	line->instr = NULL;
	line->next = NULL;
	line->type = 0;
	return (line);
}

void	add_line(t_data *data, t_line *line)
{
	if (data->lst)
	{
		data->last.line->next = line;
		data->last.line = line;
	}
	else
	{
		data->lst = line;
		data->last.line = line;
	}
}

void	parse_file(t_data *data, int fd)
{
	int		e;
	t_line	*line;
	int		l;

	while (1)
	{
		l = data->nl;
		e = read_line(data, fd);
		if (data->tlst)
		{
			line = new_line(data, e, fd, l);
			add_line(data, line);
		}
		if (e)
		{
			(data->nl)++;
			data->nt = 0;
		}
		else
			break ;
	}
	close(fd);
	if (!(data->lst))
		null_lst(data);
}
