/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:49:00 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/27 10:22:20 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_line(t_line *line)
{
	t_token	*tok;

	while (line->lst)
	{
		tok = line->lst->next;
		free(line->lst->cnt);
		free(line->lst);
		line->lst = tok;
	}
}

void	free_data(t_data *data)
{
	t_line	*line;
	t_label	*label;

	free(data->file);
	while (data->lst)
	{
		line = data->lst->next;
		free_line(data->lst);
		free(data->lst);
		data->lst = line;
	}
	while (data->lab)
	{
		label = data->lab->next;
		free(data->lab);
		data->lab = label;
	}
}
