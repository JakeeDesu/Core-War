/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_what.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:43:49 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/27 11:44:29 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	is_what(t_data *data, int fd, char c)
{
	data->last.tok->t = 8;
	if (c > '9' || c < '0')
		data->last.tok->t = 3;
	while (read(fd, &c, 1))
	{
		if (!(label_chars(c, LABEL_CHARS)))
		{
			if (c == LABEL_CHAR)
			{
				data->last.tok->t = 2;
				(data->nt)++;
			}
			else
				lseek(fd, -1, SEEK_CUR);
			break ;
		}
		if (c > '9' || c < '0')
			data->last.tok->t = 3;
		(data->nt)++;
	}
	get_cnt(data, fd);
}
