/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 21:18:11 by iberchid          #+#    #+#             */
/*   Updated: 2018/10/11 12:49:31 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = (char*)haystack;
	if (str[i] == '\0' && needle[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while ((str[i] != '\0') && (needle[j] != '\0')
				&& (str[i] == needle[j]))
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return (str + i - j);
		else if (str[i] == '\0')
			return (0);
		else
			i = i - j + 1;
	}
	return (0);
}
