/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_reg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:29:01 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/27 14:25:24 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	is_reg(t_data *d, int fd)
{
	char	c;

	d->last.tok->t = 6;
	while (read(fd, &c, 1))
	{
		if (!(label_chars(c, LABEL_CHARS)))
		{
			if (c == LABEL_CHAR)
			{
				d->last.tok->t = 2;
				(d->nt)++;
			}
			else
				lseek(fd, -1, SEEK_CUR);
			break ;
		}
		if (c > '9' || c < '0')
			d->last.tok->t = 3;
		(d->nt)++;
	}
	if (d->last.tok->t == 6)
		if (d->nt - d->last.tok->nt + 1 > 3 || d->nt == d->last.tok->nt)
			d->last.tok->t = 3;
	get_cnt(d, fd);
}
