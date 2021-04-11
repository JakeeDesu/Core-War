/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 05:56:31 by iberchid          #+#    #+#             */
/*   Updated: 2018/10/12 08:10:12 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memndup(size_t size)
{
	size_t	n;
	char	*str;

	n = 0;
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (n < size)
		str[n++] = '\0';
	return ((void *)str);
}
