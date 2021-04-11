/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <hmhindat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:08:56 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/18 19:20:34 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	write_mem(t_vm *vm, size_t address, int *value, size_t byte_nb)
{
	size_t			cursor;
	unsigned int	val;
	int				posi;

	cursor = 0;
	val = (unsigned int)(*value);
	while (cursor < byte_nb)
	{
		posi = correct_addr(address + cursor);
		vm->arena.mem[posi] = ((unsigned char*)&val)[byte_nb - cursor - 1];
		if (vm->current_carr)
			vm->arena.color[posi] = (vm->current_carr->r)[0];
		cursor++;
	}
}
