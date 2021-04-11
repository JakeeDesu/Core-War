/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <hmhindat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:47:24 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/28 10:32:33 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		print_usage(void)
{
	ft_putstr("USAGE : [-d N -dump N -v N -V ] [-a] <champion1.cor> <...>\n");
	ft_putstr("\t#####################################################\n");
	ft_putstr("\t-a\t\t: Prints output from \"aff\" (Default is to hide it)\n");
	ft_putstr("\t-d\tN\t: Dumps memory 32 after N cycles then exits\n");
	ft_putstr("\t-dump\tN\t: Dumps memory 64 after N cycles then exits\n");
	ft_putstr("\t-v\tN\t: Show infos\n");
	ft_putstr("\t\t\t\t- 2 : Show cycles\n");
	ft_putstr("\t\t\t\t- 4 : Show operations\n");
	ft_putstr("\t\t\t\t- 6 : Show both\n");
	ft_putstr("\t-V\t\t: Visualizer\n");
	ft_putstr("\t-n\tN\t: Change player order\n");
	ft_putstr("\t#####################################################\n");
}

int			main(int argc, char **argv)
{
	t_vm	*vm;

	if (argc > 1)
	{
		vm = init_vm();
		init_arena(vm);
		get_player_list(argc, argv, vm);
		load_players(vm);
		(vm->vis_flag != 1) ? announce_players(vm) : NULL;
		if ((vm->v_flag == 4 || vm->v_flag == 6) && !(vm->vis_flag))
			vm->op_flag = 1;
		loop(vm);
		clean_exit(&(vm->mem));
	}
	else
		print_usage();
	return (0);
}
