C_FILES= corewar.c					\
		my_mallo.c					\
		to_hex.c					\
		flag_n.c					\
		flag_vis.c					\
		flag_v.c					\
		flag_d.c					\
		fix_order.c					\
		posi_player.c				\
		read_header.c				\
		init_arena.c				\
		get_player_list.c			\
		show_header.c				\
		affich_arena.c 				\
		print_str_color.c			\
		check_order_nbr.c			\
		init_vm.c					\
		load_players.c				\
		check_header.c				\
		check_op_id.c				\
		init_carriages.c			\
		ft_carriages.c				\
		max_check.c					\
		ft_max_check.c				\
		announce_players.c			\
		print_address.c				\
		loop.c						\
		scan_carriage.c				\
		op.c						\
		parse/read_mem.c			\
		parse/write_mem.c			\
		parse/correct_addr.c		\
		utilities/check_arg_type.c	\
		utilities/get_args.c		\
		utilities/read_arg.c		\
		utilities/type_size.c		\
		operations/live.c			\
		operations/sti.c			\
		operations/and.c			\
		operations/or.c				\
		operations/xor.c			\
		operations/st.c				\
		operations/ld.c				\
		operations/zjmp.c			\
		operations/add.c			\
		operations/sub.c			\
		operations/ldi.c			\
		operations/lldi.c			\
		operations/fork.c			\
		operations/lfork.c			\
		operations/lld.c			\
		operations/aff.c			\
		visual.c

O_FILES=$(C_FILES:.c=.o)
LIB_PATH=libft
HEADER=corewar.h
LIB=libft.a
VLIB = -lncurses
NAME=../corewar
CC=gcc
FLAGS= -Wall -Wextra -Werror

all : lib_ft $(NAME)

$(NAME): $(LIB_PATH)/$(LIB) $(O_FILES)
	$(CC) -o $(NAME) $(O_FILES) $(LIB_PATH)/$(LIB) $(VLIB)

$(O_FILES): %.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

lib_ft:
	make -C $(LIB_PATH)

clean :
	make clean -C $(LIB_PATH)
	rm -rf $(O_FILES)

fclean: clean
	make fclean -C $(LIB_PATH)
	rm -rf $(NAME)

re: fclean all
