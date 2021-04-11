/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:50:45 by iberchid          #+#    #+#             */
/*   Updated: 2018/10/12 09:24:13 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cal_len_l(char const *s)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\n'))
		{
			n++;
			i++;
		}
		else
			return (n);
	}
	return (n);
}

int		cal_len_r(char const *s)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
		i++;
	if (i > 0)
		i--;
	while (i != 0)
	{
		if ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\n'))
		{
			n++;
			i--;
		}
		else
			return (n);
	}
	return (n);
}

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	n;
	unsigned int	m;
	char			*str;

	if (s)
	{
		i = 0;
		j = 0;
		n = cal_len_l(s);
		m = cal_len_r(s);
		while (s[i] != '\0')
			i++;
		if (!(str = (char*)malloc(sizeof(char) * (i - m - n + 1))))
			return (NULL);
		while (n < (i - m))
			str[j++] = s[n++];
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}
