/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 06:34:53 by iberchid          #+#    #+#             */
/*   Updated: 2018/10/11 08:14:16 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	n;
	char	*str;

	n = 0;
	if (!(str = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	while (n < size)
	{
		str[n] = 0;
		n++;
	}
	if (n == size)
		return ((void*)str);
	else
		return (NULL);
}
