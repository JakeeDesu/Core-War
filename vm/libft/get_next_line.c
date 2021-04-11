/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 20:46:52 by hmhindat          #+#    #+#             */
/*   Updated: 2019/01/20 21:01:50 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_buff_h	*init_saver(t_list **fd_saver, int fd)
{
	t_list		*p_fd;
	t_buff_h	*l_buff;

	p_fd = *fd_saver;
	while (p_fd)
	{
		if (((t_buff_h*)(p_fd->content))->fd == fd)
			return (p_fd->content);
		p_fd = p_fd->next;
	}
	if (!(l_buff = (t_buff_h*)malloc(sizeof(t_buff_h))))
		return (NULL);
	l_buff->fd = fd;
	l_buff->lost = ft_strdup("");
	ft_lstadd(fd_saver, ft_lstnew(l_buff, sizeof(t_buff_h)));
	free(l_buff);
	l_buff = NULL;
	return ((*fd_saver)->content);
}

void		fd_close(t_list **fd_holder, char **line, int ret[][2], int fd)
{
	t_list *p_fd;
	t_list *del_fd;

	if (fd < 0 || (*ret)[1] == -1)
		(*ret)[0] = -1;
	if ((*ret)[0] == 0 || (*ret)[0] == -1)
		*line = ft_strdup("");
	p_fd = *fd_holder;
	if (((t_buff_h*)(p_fd->content))->fd == fd)
	{
		free(p_fd->content);
		free(p_fd);
		*fd_holder = NULL;
	}
	else
	{
		while (((t_buff_h*)(p_fd->next->content))->fd != fd)
			p_fd = p_fd->next;
		del_fd = p_fd->next;
		p_fd->next = p_fd->next->next;
		free(del_fd->content);
		free(del_fd);
		del_fd = NULL;
	}
}

int			read_line(char **line, char *buffer, t_list **fd_saver, int fd)
{
	char	*endl;
	char	*newline;
	size_t	new_len;

	new_len = ft_strlen(*line) + 1;
	if (!(endl = ft_strchr(buffer, '\n')))
		new_len += ft_strlen(buffer);
	else
	{
		new_len += endl - buffer;
		free((init_saver(fd_saver, fd))->lost);
		(init_saver(fd_saver, fd))->lost = ft_strdup((endl + 1));
	}
	if (!(newline = (char*)malloc(new_len * sizeof(char))))
		return (-1);
	ft_strncpy(newline, *line, new_len);
	ft_strlcat(newline, buffer, new_len);
	free(*line);
	*line = newline;
	if (endl)
		return (0);
	if (ft_strlen(buffer) < (size_t)BUFF_SIZE)
		return (0);
	return (1);
}

int			eline_corr(char **line, t_list **fd_saver, int fd)
{
	char		*newlost;
	char		*endl;
	t_buff_h	*lost_h;

	lost_h = init_saver(fd_saver, fd);
	if (!(endl = ft_strchr((lost_h->lost), '\n')))
	{
		*line = ft_strdup(lost_h->lost);
		return (0);
	}
	else
	{
		if (!(*line = (char*)malloc(sizeof(char) * (endl - lost_h->lost + 1))))
			return (-1);
		ft_strncpy(*line, (lost_h->lost), (endl - lost_h->lost + 1));
		(*line)[endl - lost_h->lost] = '\0';
		newlost = ft_strdup(endl + 1);
		free(lost_h->lost);
		lost_h->lost = newlost;
		newlost = NULL;
		return (1);
	}
}

int			get_next_line(int fd, char **line)
{
	static t_list	*fd_saver;
	char			*buff;
	int				ret[2];

	ret[0] = 0;
	if (!(buff = (char*)malloc(BUFF_SIZE + 1)) || BUFF_SIZE < 0 || !line)
		return (-1);
	buff[BUFF_SIZE] = '\0';
	if ((ret[0] = eline_corr(line, &fd_saver, fd)))
		return (ret[0]);
	while ((ret[1] = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (!(ret[0] = read_line(line, buff, &fd_saver, fd)))
		{
			if (!(ret[0]))
				ret[0] = 1;
			free(buff);
			buff = NULL;
			return (ret[0]);
		}
		ft_strclr(buff);
	}
	fd_close(&fd_saver, line, &ret, fd);
	return (ret[0]);
}
