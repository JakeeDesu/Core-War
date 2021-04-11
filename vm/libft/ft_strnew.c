/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 07:01:08 by iberchid          #+#    #+#             */
/*   Updated: 2018/10/11 08:19:06 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	n;
	char	*str;

	n = 0;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (n < size)
	{
		str[n] = 0;
		n++;
	}
	if (n == size)
	{
		str[n] = '\0';
		return (str);
	}
	else
		return (NULL);
}
