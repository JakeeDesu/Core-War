/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:14:09 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/27 11:15:19 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_cmnt(t_data *data, int fd)
{
	char	tab[9];
	int		i;

	i = 0;
	while (i < 8)
	{
		if (!(read(fd, tab + i, 1)))
			lexical_error(data, fd, data->nl, data->last.tok->nt);
		i++;
	}
	tab[8] = '\0';
	if (!(cmp_str(tab, COMMENT_CMD_STRING)))
	{
		data->nt = data->nt + 7;
		data->last.tok->t = 1;
		get_cnt(data, fd);
		return (1);
	}
	else
		return (0);
}

int		check_name(t_data *data, int fd)
{
	char	tab[6];
	int		i;

	i = 0;
	while (i < 5)
	{
		if (!(read(fd, tab + i, 1)))
			lexical_error(data, fd, data->nl, data->last.tok->nt);
		i++;
	}
	tab[5] = '\0';
	if (!(cmp_str(tab, NAME_CMD_STRING)))
	{
		data->nt = data->nt + 4;
		data->last.tok->t = 0;
		get_cnt(data, fd);
		return (1);
	}
	else
		return (0);
}

void	if_cmd(t_data *data, int fd)
{
	lseek(fd, -1, SEEK_CUR);
	if (!(check_name(data, fd)))
	{
		lseek(fd, -5, SEEK_CUR);
		if (!(check_cmnt(data, fd)))
			lexical_error(data, fd, data->nl, data->last.tok->nt);
	}
}
