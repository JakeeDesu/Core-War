/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 07:52:58 by iberchid          #+#    #+#             */
/*   Updated: 2018/10/12 09:53:15 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	if (s)
	{
		i = 0;
		j = 0;
		while (s[i] != '\0')
			i++;
		if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		while (j < i)
		{
			str[j] = f(s[j]);
			j++;
		}
		str[j] = '\0';
		return (str);
	}
	else
		return (NULL);
}
