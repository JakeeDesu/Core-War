NAME = ../asm
OBJ	= 	error_parser.o\
		func.o\
		if_cmd.o\
		is_dir.o\
		is_label.o\
		is_num.o\
		is_reg.o\
		is_string.o\
		is_what.o\
		main.o\
		operations.o\
		parser.o\
		token.o\
		print.o\
		syntax.o\
		error_syntax.o\
		size.o\
		invalid.o\
		value.o\
		output.o\
		free.o 
HEADER = asm.h

all	: $(NAME)
	
$(NAME) : $(OBJ)
	gcc -o $(NAME) $(OBJ)
	
%.o : %.c $(HEADER)
	gcc -Wall -Wextra -Werror  -c $< 

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
