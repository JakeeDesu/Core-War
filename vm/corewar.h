/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 04:25:20 by hmhindat          #+#    #+#             */
/*   Updated: 2020/11/28 12:44:30 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_COREWAR_H
# define H_COREWAR_H
# include "libft/libft.h"
# include "op.h"
# include <math.h>
# include <stdio.h>
# include <ncurses.h>
# include <time.h>

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"

typedef struct s_arena		t_arena;
typedef struct s_player		t_player;
typedef struct s_carriage	t_carriage;
typedef struct s_vm			t_vm;
typedef void	(*t_fun)(t_vm *, t_carriage *);
typedef struct s_vis		t_vis;

struct			s_vis
{
	int				height;
	int				width;
	int				start_y;
	int				start_x;
	WINDOW			*win;
	int				max_x;
	int				max_y;
	int				m_height;
	int				m_width;
	int				m_start_y;
	int				m_start_x;
	WINDOW			*menu;
	int				w_height;
	int				w_width;
	int				w_start_y;
	int				w_start_x;
	WINDOW			*winner;
};

struct			s_arena
{
	unsigned char	mem[MEM_SIZE];
	int				color[MEM_SIZE];
	int				carr[MEM_SIZE];
};

struct			s_player
{
	int				flag_id;
	int				id;
	char			color;
	t_header		header;
	int				lives;
	unsigned char	*exec_code;
};

struct			s_carriage
{
	size_t			id;
	unsigned char	carry;
	unsigned char	op_id;
	size_t			last_live_performed;
	int				nb_of_lives;
	int				cycles_remaining;
	size_t			current_position;
	int				to_be_crossed;
	int				r[REG_NUMBER];
	int				sleep;
	int				dead;
	t_carriage		*next;
	t_carriage		*prev;
};

struct			s_vm
{
	t_vis			v_data;
	t_arena			arena;
	size_t			players_nb;
	t_player		*players;
	t_player		*players_cp;
	int				n_flag;
	int				dump_flag;
	int				dump_cycle;
	int				v_flag;
	int				vis_flag;
	int				a;
	int				op_flag;
	size_t			alive_player_p;
	int				player_max_live;
	size_t			number_of_cycles;
	int				cycle;
	size_t			live_op_performed;
	int				cycle_to_die;
	size_t			number_of_checks;
	size_t			carr_uid;
	t_carriage		*carriages;
	t_carriage		*current_carr;
	t_list			*mem;
	t_fun			op_funs[16];
};

t_op			g_op_tab[17];
void			show_args(t_carriage *carr, int val1, int val2, int val3);
void			show_reg(t_carriage *carr);
int				check_op_id(unsigned char op_id, t_vm *vm);
void			procs_infos(t_vm *vm);
int				flag_n(t_vm *vm, char **argv, int argc, int *nb);
void			flag_v(t_vm *vm, char **argv, int argc, int *nb);
void			flag_vis(t_vm *vm, char **argv, int argc, int *nb);
void			flag_d(t_vm *vm, char **argv, int argc, int *nb);
void			*mallo(t_list **mem, size_t size);
void			clean_exit(t_list **mem);
int				check_order_nbr(char *str);
void			fix_order(t_vm *vm);
unsigned char	*read_byte(int fd, size_t size);
t_header		read_header(int fd);
void			check_header(t_header *header);
void			show_header(t_header header);
char			*to_hex(void *bytes, size_t size);
void			print_hex(unsigned char hex, char color_id);
void			print_str_color(char color_id);
void			show_player(t_vm *vm);
void			affich_arena(t_arena arena, int dump_flag);
void			init_arena(t_vm *vm);
void			get_player_list(int argc, char **argv, t_vm *vm);
void			load_players(t_vm *vm);
t_vm			*init_vm(void);
void			init_carriages(t_vm *vm);
t_carriage		*new_carriage(t_vm *vm, t_carriage *cp_carr);
t_carriage		*add_carr(t_vm *vm, t_carriage **carr);
int				mark_dead_carriages(t_vm *vm);
void			delete_dead_carriages(t_vm *vm, int kill_all);
void			announce_players(t_vm *vm);
void			print_address(size_t line, size_t i);
void			print_carr_info(t_carriage *carr, t_vm *vm);
char			scan_carr(t_vm *vm);
void			loop(t_vm *vm);
int				read_mem(t_vm *vm, size_t posi, size_t byte_nb);
void			write_mem(t_vm *vm, size_t address, int *value, size_t byte_nb);
int				correct_addr(int address);
int				valid_arg_type(unsigned char op, unsigned char arg_type,
				int *types);
int				check_arg_type(t_vm *vm, int *types, t_carriage *carr);
int				get_args(t_vm *vm, int *args, int *types, t_carriage *carr);
int				read_arg(t_vm *vm, int arg_nb, unsigned char *type,
				t_carriage *carr);
int				type_size(int type, int t_dir_size);
int				check_reg_val(int op_id, int *types, int *args);
void			check_carriages(t_vm *vm, int kill_all);
int				jump_args(int op_id, int *types);
void			op_info(t_vm *vm, t_carriage *carr);
void			live(t_vm *vm, t_carriage *carriage);
void			st(t_vm *vm, t_carriage *carriage);
void			sti(t_vm *vm, t_carriage *carriage);
void			ld(t_vm *vm, t_carriage *carriage);
void			and(t_vm *vm, t_carriage *carriage);
void			or(t_vm *vm, t_carriage *carriage);
void			xor(t_vm *vm, t_carriage *carriage);
void			zjmp(t_vm *vm, t_carriage *carriage);
void			add(t_vm *vm, t_carriage *carriage);
void			sub(t_vm *vm, t_carriage *carriage);
void			ldi(t_vm *vm, t_carriage *carriage);
void			lldi(t_vm *vm, t_carriage *carriage);
void			op_fork(t_vm *vm, t_carriage *carriage);
void			aff(t_vm *vm, t_carriage *carriage);
void			lfork(t_vm *vm, t_carriage *carriage);
void			lld(t_vm *vm, t_carriage *carriage);
void			draw_arena(t_vm *vm, WINDOW *win);
void			print_winner_screen(t_vm *vm);
void			dup_players_cp(t_vm *vm);
void			posi_player(t_vm *vm);

#endif
