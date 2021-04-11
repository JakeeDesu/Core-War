/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:33:57 by ouzamhar          #+#    #+#             */
/*   Updated: 2021/01/27 18:09:46 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*check_file(char *name)
{
	int		i;
	char	*file;

	i = 0;
	while (name[i])
	{
		if (name[i] == '.')
		{
			if (!(cmp_str(name + i, ".s")))
			{
				if (!(file = malloc(sizeof(char) * (i + 5))))
					exit(0);
				str_cpy(name, file, i);
				str_cpy(".cor", file + i, 5);
				return (file);
			}
		}
		i++;
	}
	print_str("invalid file\n");
	exit(0);
}

int		init_data(t_data *data, char *name)
{
	int	fd;

	data->nl = 1;
	data->nt = 0;
	data->file = check_file(name);
	data->lst = NULL;
	data->lab = NULL;
	data->name = NULL;
	data->comment = NULL;
	data->header.magic = COREWAR_EXEC_MAGIC;
	data->header.prog_size = 0;
	if ((fd = open(name, O_RDONLY)) == -1)
	{
		print_str("Can't read source file ");
		print_str(name);
		print_str("\n");
		free(data->file);
		exit(0);
	}
	return (fd);
}

int		main(int gc, char **gv)
{
	t_data	data;
	int		fd;

	if (gc != 2)
	{
		print_str("Usage: ./asm <sourcefile.s>\n");
		exit(0);
	}
	fd = init_data(&data, gv[1]);
	parse_file(&data, fd);
	check_syntax(&data);
	get_size(&data);
	get_value(&data);
	to_byecode(&data);
	print_str("Writing output program to ");
	print_str(data.file);
	print_str("\n");
	free_data(&data);
	return (0);
}
