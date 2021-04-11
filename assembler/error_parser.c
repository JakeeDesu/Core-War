/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:12:30 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/27 14:42:41 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	null_lst(t_data *data)
{
	print_str("Syntax error at token [TOKEN][");
	tok_num(data->nl);
	if (!(data->nt))
		(data->nt)++;
	print_char(':');
	tok_num(data->nt);
	print_str("] END \"(null)\"\n");
	free_data(data);
	exit(0);
}

void	lexical_error(t_data *data, int fd, int l, int t)
{
	close(fd);
	print_str("Lexical error at [");
	print_nbr(l);
	print_char(':');
	print_nbr(t);
	print_str("]\n");
	free_data(data);
	exit(0);
}
