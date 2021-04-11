/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:19:32 by iberchid          #+#    #+#             */
/*   Updated: 2018/10/12 09:33:47 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		calc_len(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	while (s1[i] != '\0')
	{
		i++;
		n++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		i++;
		n++;
	}
	return (n - 2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	n;
	char			*str;

	if (s1 && s2)
	{
		i = 0;
		j = 0;
		n = calc_len(s1, s2);
		if (!(str = (char*)malloc(sizeof(char) * (n + 1))))
			return (NULL);
		while (s1[j] != '\0')
			str[i++] = s1[j++];
		j = 0;
		while (s2[j] != '\0')
			str[i++] = s2[j++];
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}
