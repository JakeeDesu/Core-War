/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:16:59 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/27 14:43:19 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	syntax_endline(t_data *data, t_line *line)
{
	print_str("Syntax error at token [TOKEN][");
	tok_num(line->nl);
	print_char(':');
	tok_num(line->nt);
	print_str("] ENDLINE\n");
	free_data(data);
	exit(0);
}

void	syntax_error(t_data *data, t_token *tok)
{
	print_str("Syntax error at token [TOKEN][");
	tok_num(tok->nl);
	print_char(':');
	tok_num(tok->nt);
	print_str("] ");
	print_str(g_type[tok->t]);
	print_str(" \"");
	print_str(tok->cnt);
	print_str("\"\n");
	free_data(data);
	exit(0);
}
