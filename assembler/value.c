/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:57:32 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/27 11:18:25 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_atoi(char *str)
{
	int	i;
	int	s;

	s = 1;
	i = 0;
	if (*str == '-')
	{
		s = -1;
		str++;
	}
	while (*str)
	{
		i = i * 10 + (*str - '0');
		str++;
	}
	return (i * s);
}

int		lab_value(t_data *data, char *str, t_token *token)
{
	t_label	*label;

	label = data->lab;
	while (label)
	{
		if (!(cmp_str(str, label->name)))
			return (label->line->size);
		label = label->next;
	}
	invalid_label(data, token, str);
	return (0);
}

void	size_argi(t_data *data, t_line *line)
{
	int		i;
	int		l;
	t_token	*arg;

	i = 0;
	while (i < line->p)
	{
		arg = line->arg[i];
		if (arg->t == 6 || arg->t == 7)
			arg->val = ft_atoi(arg->cnt + 1);
		else if (arg->t == 8)
			arg->val = ft_atoi(arg->cnt);
		else if (arg->t == 9)
		{
			l = lab_value(data, arg->cnt + 2, arg);
			arg->val = l - line->size;
		}
		else
		{
			l = lab_value(data, arg->cnt + 1, arg);
			arg->val = -line->size + l;
		}
		i++;
	}
}

void	get_value(t_data *data)
{
	t_line	*line;

	line = data->lst;
	while (line)
	{
		if (line->instr)
			size_argi(data, line);
		line = line->next;
	}
}
