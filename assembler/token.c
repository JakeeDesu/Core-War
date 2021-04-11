/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:35:31 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/27 14:45:43 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		*new_token(t_data *data, int fd)
{
	t_token	*token;

	if (!(token = malloc(sizeof(t_token))))
	{
		free_data(data);
		close(fd);
		exit(0);
	}
	token->nl = data->nl;
	token->nt = data->nt;
	token->cnt = NULL;
	token->next = NULL;
	return (token);
}

void		add_token(t_data *data, t_token *token)
{
	if (data->tlst)
	{
		data->last.tok->next = token;
		data->last.tok = token;
	}
	else
	{
		data->tlst = token;
		data->last.tok = token;
	}
}

void		is_seperator(t_data *data, int fd)
{
	char	*cnt;

	if (!(cnt = malloc(sizeof(char) * 2)))
	{
		free_data(data);
		close(fd);
		exit(0);
	}
	str_cpy(",", cnt, 2);
	data->last.tok->cnt = cnt;
	data->last.tok->t = 4;
}

void		read_token(t_data *data, int fd, char c)
{
	t_token *token;

	token = new_token(data, fd);
	add_token(data, token);
	if (c == SEPARATOR_CHAR)
		is_seperator(data, fd);
	else if (c == '"')
		is_string(data, fd);
	else if (c == LABEL_CHAR)
		is_label(data, fd);
	else if (c == '-')
		is_num(data, fd);
	else if (c == '%')
		is_dir(data, fd);
	else if (c == 'r')
		is_reg(data, fd);
	else if (label_chars(c, LABEL_CHARS))
		is_what(data, fd, c);
	else
		if_cmd(data, fd);
}
