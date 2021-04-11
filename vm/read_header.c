/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:18:23 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/20 03:51:06 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	read_magic(int fd)
{
	unsigned int	magic;
	unsigned int	magic_h;

	magic = 0;
	magic_h = COREWAR_EXEC_MAGIC;
	if ((read(fd, &magic, 4)) > 0)
	{
		magic = (
				(magic & 0x000000ff) << 24 |
				(magic & 0x0000ff00) << 8 |
				(magic & 0x00ff0000) >> 8 |
				(magic & 0xff000000) >> 24);
		return (magic);
	}
	ft_putstr("error: \n\tmagic code error\n");
	exit(0);
}

int				load_prog_name(int fd, char *prog_name)
{
	if ((read(fd, prog_name, PROG_NAME_LENGTH)))
	{
		prog_name[PROG_NAME_LENGTH + 1] = '\0';
		return (1);
	}
	ft_putstr("error:\n\treading prog name\n");
	exit(0);
}

unsigned int	read_prog_size(int fd)
{
	unsigned int	prog_size;
	unsigned char	byte;
	int				i;

	i = 0;
	prog_size = 0;
	while (i < 4)
	{
		if ((read(fd, &byte, 1)) > 0)
		{
			prog_size = prog_size << 8;
			prog_size = prog_size | byte;
		}
		else
		{
			ft_putstr("error:\n\treading prog size\n");
			exit(0);
		}
		i++;
	}
	return (prog_size);
}

int				load_comment(int fd, char *comment)
{
	if ((read(fd, comment, COMMENT_LENGTH)))
	{
		comment[COMMENT_LENGTH + 1] = '\0';
		return (1);
	}
	ft_putstr("error:\n\treading comment\n");
	exit(0);
}

t_header		read_header(int fd)
{
	t_header	header;
	char		null[4];

	header.magic = read_magic(fd);
	load_prog_name(fd, header.prog_name);
	read(fd, null, 4);
	header.prog_size = read_prog_size(fd);
	load_comment(fd, header.comment);
	read(fd, null, 4);
	return (header);
}
