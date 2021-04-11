/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 08:36:36 by iberchid          #+#    #+#             */
/*   Updated: 2018/10/12 10:14:43 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (s1 && s2)
	{
		i = 0;
		while ((s1[i] == s2[i]) && (s1[i] != '\0')
				&& (s2[i] != '\0') && (i < n))
			i++;
		if (i == n)
			return (1);
		else if (s1[i] == s2[i])
			return (1);
		else
			return (0);
	}
	return (0);
}
