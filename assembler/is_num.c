/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:05:03 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/27 11:49:30 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	is_num(t_data *data, int fd)
{
	char	c;

	data->last.tok->t = 8;
	while (read(fd, &c, 1))
	{
		if (c > '9' || c < '0')
		{
			lseek(fd, -1, SEEK_CUR);
			break ;
		}
		(data->nt)++;
	}
	if (data->nt == data->last.tok->nt)
		lexical_error(data, fd, data->nl, data->last.tok->nt);
	get_cnt(data, fd);
}
