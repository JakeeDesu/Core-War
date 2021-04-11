/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:15:03 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/27 11:50:01 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_cmd(t_data *data)
{
	t_token *tok;
	int		i;

	i = 0;
	tok = data->last.line->lst;
	if (tok->t == 0 && !(data->name))
		i = 0;
	else if (tok->t == 1 && !(data->comment))
		i = 1;
	else
		syntax_error(data, tok);
	if (!(tok = tok->next))
		syntax_endline(data, data->last.line);
	if (tok->t != 5)
		syntax_error(data, tok);
	if (i == 0)
		data->name = tok;
	else
		data->comment = tok;
	if ((tok = tok->next))
		syntax_error(data, tok);
}

void	cmd_lines(t_data *data)
{
	check_cmd(data);
	if (!(data->last.line = data->last.line->next))
		null_lst(data);
	check_cmd(data);
	if (!(data->last.line = data->last.line->next))
		null_lst(data);
}

void	order_instr(t_data *data, t_line *line, t_token *tok)
{
	int	s;

	s = 1;
	if (tok->t != 3)
		syntax_error(data, tok);
	line->instr = tok;
	if (!(tok = tok->next))
		syntax_endline(data, line);
	while (tok)
	{
		if (s == 0 && tok->t == 4)
			s = 1;
		else if (s == 1 && tok->t > 5)
		{
			s = 0;
			(line->p)++;
		}
		else
			syntax_error(data, tok);
		tok = tok->next;
	}
	if (s == 1)
		syntax_endline(data, line);
}

void	check_order(t_data *data, t_line *line)
{
	t_token *tok;

	while (line)
	{
		tok = line->lst;
		if (tok->t == 2)
		{
			creat_label(data, line, tok);
			tok = tok->next;
		}
		if (tok)
			order_instr(data, line, tok);
		if (!(line->e))
			null_lst(data);
		line = line->next;
	}
}

void	check_syntax(t_data *data)
{
	data->last.line = data->lst;
	cmd_lines(data);
	check_order(data, data->last.line);
}
