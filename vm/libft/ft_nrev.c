/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nrev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 07:27:20 by iberchid          #+#    #+#             */
/*   Updated: 2018/10/20 10:06:54 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nrev(char *str, size_t size)
{
	size_t	i;
	size_t	n;
	char	*s;

	i = 0;
	n = 0;
	if (str)
	{
		while ((i < size) && (str[i] != '\0'))
			i++;
		if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		while (i > 0)
			s[n++] = str[(i--) - 1];
		s[n] = '\0';
		return (s);
	}
	return (NULL);
}
