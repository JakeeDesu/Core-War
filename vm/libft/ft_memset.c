/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 21:32:37 by iberchid          #+#    #+#             */
/*   Updated: 2018/10/08 22:13:03 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	n;
	char	*s;

	n = 0;
	s = (char*)str;
	while (n < len)
	{
		s[n] = c;
		n++;
	}
	str = (void*)s;
	return (str);
}
