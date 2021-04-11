/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_label.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:20:06 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/26 18:27:16 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	is_label(t_data *data, int fd)
{
	char	c;

	data->last.tok->t = 10;
	while (read(fd, &c, 1))
	{
		if (!(label_chars(c, LABEL_CHARS)))
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
