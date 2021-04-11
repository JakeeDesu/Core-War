/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_addr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:06:31 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/11 17:07:04 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		correct_addr(int address)
{
	if (address < 0)
		address = MEM_SIZE + (address % MEM_SIZE);
	address = address % MEM_SIZE;
	return (address);
}
