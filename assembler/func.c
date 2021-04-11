/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:27:11 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/27 14:43:37 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	creat_label(t_data *data, t_line *line, t_token *tok)
{
	t_label *l;

	if (!(l = malloc(sizeof(t_label))))
	{
		free_data(data);
		exit(0);
	}
	l->line = line;
	tok->cnt[tok->h - 1] = '\0';
	l->name = tok->cnt;
	l->next = NULL;
	if (data->lab)
	{
		data->last.label->next = l;
		data->last.label = l;
	}
	else
	{
		data->lab = l;
		data->last.label = l;
	}
}

int		label_chars(char c, char *chars)
{
	while (*chars)
	{
		if (*chars == c)
			return (1);
		chars++;
	}
	return (0);
}

void	get_cnt(t_data *data, int fd)
{
	int		l;

	l = data->nt - data->last.tok->nt + 1;
	data->last.tok->cnt = malloc(sizeof(char) * (l + 1));
	lseek(fd, -l, SEEK_CUR);
	read(fd, data->last.tok->cnt, l);
	data->last.tok->h = l;
	data->last.tok->cnt[l] = '\0';
}

int		cmp_str(const char *str1, const char *str2)
{
	int		i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	str_cpy(char *src, char *dst, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}
