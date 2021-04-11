/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 23:27:29 by iberchid          #+#    #+#             */
/*   Updated: 2018/10/11 11:38:47 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	overlap(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if ((src + i) == dest)
			return (1);
		i++;
	}
	return (0);
}

static void		*if_over(void *dest, const void *src, size_t len)
{
	size_t	n;
	char	*s1;
	char	*s2;

	n = len;
	s1 = (char*)dest;
	s2 = (char*)src;
	while (!(n == 0))
	{
		s1[n - 1] = s2[n - 1];
		n--;
	}
	return (dest);
}

static void		*if_nover(void *dest, const void *src, size_t len)
{
	size_t	n;
	char	*s1;
	char	*s2;

	n = 0;
	s1 = (char*)dest;
	s2 = (char*)src;
	while (n < len)
	{
		s1[n] = s2[n];
		n++;
	}
	return (dest);
}

void			*ft_memmove(void *dest, const void *src, size_t len)
{
	if (overlap(dest, src, len) == 1)
	{
		dest = if_over(dest, src, len);
		return (dest);
	}
	else
	{
		dest = if_nover(dest, src, len);
		return (dest);
	}
}
