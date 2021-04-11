/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mallo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 03:28:24 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/20 04:46:02 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	del_content(void *content, size_t size)
{
	if (content)
	{
		size = 0 * (int)content;
		free(content);
	}
}

void	clean_exit(t_list **mem)
{
	ft_lstdel(mem, &del_content);
	exit(0);
}

void	*mallo(t_list **mem, size_t size)
{
	t_list	*new_elem;

	if (!(new_elem = ft_lstnew(NULL, size)))
	{
		ft_lstdel(mem, &del_content);
		ft_putstr("mem list deleted\n");
		exit(0);
	}
	ft_lstadd(mem, new_elem);
	return (new_elem->content);
}
