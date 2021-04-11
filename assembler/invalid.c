/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:44:32 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/27 14:43:57 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	invalid_length(t_data *data, int l)
{
	if (l == PROG_NAME_LENGTH)
		print_str("Champion name too long (Max length 128)\n");
	else
		print_str("Champion comment too long (Max length 2048)\n");
	free_data(data);
	exit(0);
}

void	invalid_label(t_data *data, t_token *tok, char *name)
{
	print_str("No such label ");
	print_str(name);
	print_str(" while attempting to dereference token [TOKEN][");
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

void	invalid_instr(t_data *data, t_token *tok)
{
	print_str("Invalid instruction at token [TOKEN][");
	tok_num(tok->nl);
	print_char(':');
	tok_num(tok->nt);
	print_str("] INSTRUCTION \"");
	print_str(tok->cnt);
	print_str("\"\n");
	free_data(data);
	exit(0);
}

void	inv_para(t_data *data, t_line *line, int i, int t)
{
	print_str("Invalid parameter ");
	print_nbr(i);
	print_str(" type ");
	if (t == 6)
		print_str("register");
	else if (t == 7 || t == 9)
		print_str("direct");
	else
		print_str("indirect");
	print_str(" for instruction ");
	print_str(line->instr->cnt);
	print_str("\n");
	free_data(data);
	exit(0);
}
