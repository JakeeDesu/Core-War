/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 21:52:57 by iberchid          #+#    #+#             */
/*   Updated: 2018/10/11 11:41:51 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = (char*)haystack;
	while (str[i] != '\0')
	{
		j = 0;
		while ((str[i] != '\0') && (needle[j] != '\0')
				&& (str[i] == needle[j]) && i < len)
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return (str + i - j);
		else if (str[i] == '\0')
			return (0);
		else
			i = i - j;
		i++;
	}
	return (0);
}
