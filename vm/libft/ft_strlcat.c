/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 10:23:04 by iberchid          #+#    #+#             */
/*   Updated: 2018/10/10 07:09:25 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (i + 1 < size)
	{
		while ((i + j < size - 1) && (src[j] != '\0'))
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	else
	{
		if ((i + 1) == size)
			return (i + ft_strlen(src));
		return (size + ft_strlen(src));
	}
	return (i + ft_strlen(src));
}
