/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:09:24 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/27 10:11:58 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_operation(t_data *data, t_line *line)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (!(cmp_str(g_tab[i].name, line->instr->cnt)))
		{
			line->op = i + 1;
			(data->header.prog_size)++;
			if (g_tab[i].b)
				(data->header.prog_size)++;
			return (0);
		}
		i++;
	}
	invalid_instr(data, line->instr);
	return (0);
}

void	size_arg(t_data *data, t_line *line, int i)
{
	t_token	*tok;
	t_op	op;

	tok = line->arg[i];
	op = g_tab[line->op - 1];
	if (tok->t == 6 && (op.arg[i] & T_REG))
	{
		tok->size = REG_SIZE;
		line->type = line->type + (op.b & (REG_CODE << (3 - i) * 2));
	}
	else if ((tok->t == 7 || tok->t == 9) && (op.arg[i] & T_DIR))
	{
		tok->size = op.size;
		line->type = line->type + (op.b & (DIR_CODE << (3 - i) * 2));
	}
	else if ((tok->t == 8 || tok->t == 10) && (op.arg[i] & T_IND))
	{
		tok->size = IND_SIZE;
		line->type = line->type + (op.b & (IND_CODE << (3 - i) * 2));
	}
	else
		inv_para(data, line, i, tok->t);
	data->header.prog_size = data->header.prog_size + tok->size;
}

void	check_arg(t_data *data, t_line *line)
{
	t_token	*tok;
	t_op	op;
	int		i;

	i = 0;
	tok = line->instr->next;
	op = g_tab[line->op - 1];
	while (tok)
	{
		if (tok->t != 4)
		{
			if (i + 1 > op.p)
				inv_para(data, line, i, tok->t);
			line->arg[i] = tok;
			size_arg(data, line, i);
			i++;
		}
		tok = tok->next;
	}
	if (i != op.p)
		syntax_endline(data, line);
}

void	check_len(t_data *data, t_token *tok, char *dest, int l)
{
	int	i;

	i = 0;
	if (tok->h - 2 > l)
		invalid_length(data, l);
	while (tok->cnt[i + 1] != '"')
	{
		dest[i] = tok->cnt[i + 1];
		i++;
	}
	while (i <= l)
	{
		dest[i] = '\0';
		i++;
	}
}

void	get_size(t_data *data)
{
	t_line *line;

	line = data->lst;
	check_len(data, data->name, data->header.prog_name, PROG_NAME_LENGTH);
	check_len(data, data->comment, data->header.comment, COMMENT_LENGTH);
	while (line)
	{
		line->size = data->header.prog_size;
		if (line->instr)
		{
			check_operation(data, line);
			check_arg(data, line);
		}
		line = line->next;
	}
}
