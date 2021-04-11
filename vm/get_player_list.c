/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <hmhindat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:57:07 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/28 09:43:52 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		print_err(t_vm *vm, int err_id, char *flag)
{
	if (err_id == 0)
	{
		ft_putstr("USAGE ERROR:\n\t\"");
		ft_putstr(flag);
		ft_putstr("\" flag is not defined\n");
		clean_exit(&(vm->mem));
	}
}

unsigned char	*read_code(int fd, size_t prog_size, t_vm *vm)
{
	unsigned char	*prog_code;
	unsigned char	byte;
	size_t			i;
	int				checker;

	prog_code = mallo(&(vm->mem), sizeof(unsigned char) * (prog_size));
	i = 0;
	checker = 1;
	while (i < prog_size && checker > 0)
	{
		if ((checker = read(fd, &byte, 1)) > 0)
			prog_code[i] = byte;
		else
		{
			ft_putstr("error : \n\t reading code prog\n");
			clean_exit(&(vm->mem));
		}
		i++;
	}
	if (checker <= 0 || read(fd, &byte, 1) > 0)
	{
		ft_putstr("error : \n\t wrong program size\n");
		clean_exit(&(vm->mem));
	}
	return (prog_code);
}

void			read_player(char *name, t_player *player, int indx, t_vm *vm)
{
	int		fd;

	if (indx < MAX_PLAYERS && (fd = open(name, O_RDONLY)) > 0)
	{
		(player + indx)->header = read_header(fd);
		check_header(&((player + indx)->header));
		(player + indx)->exec_code = read_code(fd,
				(player + indx)->header.prog_size, vm);
		close(fd);
	}
	else
	{
		ft_putstr("ERROR: \n\tcant open -> ");
		(indx >= MAX_PLAYERS) ? ft_putstr("MAX_PLAYERS") : ft_putstr(name);
		ft_putstr("\n");
		clean_exit(&(vm->mem));
	}
}

int				get_flags(int argc, char **argv, t_vm *vm)
{
	int	nb;

	nb = 1;
	while (nb < argc && argv[nb][0] == '-')
	{
		if (ft_strcmp(argv[nb] + 1, "V") == 0)
			flag_vis(vm, argv, argc, &nb);
		else if (ft_strcmp(argv[nb] + 1, "v") == 0)
			flag_v(vm, argv, argc, &nb);
		else if (ft_strcmp(argv[nb] + 1, "a") == 0)
		{
			nb++;
			vm->a = 1;
		}
		else if (ft_strcmp(argv[nb] + 1, "dump") == 0 ||
		ft_strcmp(argv[nb] + 1, "d") == 0)
			flag_d(vm, argv, argc, &nb);
		else
			return (nb);
	}
	return (nb);
}

void			get_player_list(int argc, char **argv, t_vm *vm)
{
	int	order_id;
	int	nb;
	int	indx;

	indx = 0;
	nb = get_flags(argc, argv, vm);
	while (nb < argc && argv[nb])
	{
		order_id = -1;
		while (nb < argc && argv[nb][0] == '-')
		{
			if (ft_strcmp(argv[nb] + 1, "n") == 0)
				order_id = flag_n(vm, argv, argc, &nb);
			else
				print_err(vm, 0, argv[nb] + 1);
		}
		read_player(argv[nb++], (vm->players), indx, vm);
		if (order_id > 0 && order_id <= MAX_PLAYERS)
			vm->players[indx].flag_id = order_id;
		else
			vm->players[indx].flag_id = -1;
		vm->players[indx].id = indx + 1;
		indx++;
	}
	fix_order(vm);
}
