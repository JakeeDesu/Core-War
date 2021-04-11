/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:07:20 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/11 17:08:40 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		read_mem(t_vm *vm, size_t posi, size_t byte_nb)
{
	int			var;
	size_t		cursor;
	signed char	val;

	var = 0;
	cursor = 0;
	while (cursor < byte_nb)
	{
		val = vm->arena.mem[correct_addr(posi + cursor)];
		((signed char *)(&var))[byte_nb - cursor - 1] = val;
		cursor++;
	}
	if (byte_nb == 1)
		return ((int)((signed char)(*((signed char*)(&var)))));
	if (byte_nb == 2)
		return ((int)((short)(*((short*)(&var)))));
	return (var);
}
