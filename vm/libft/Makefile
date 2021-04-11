# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 20:07:06 by hmhindat          #+#    #+#              #
#    Updated: 2020/11/23 20:07:56 by hmhindat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FILES = 	ft_isascii.c	ft_lstiter.c	ft_memcpy.c		ft_putchar_fd.c	\
			ft_repchr.c		ft_strdel.c		ft_strlen.c		ft_strnequ.c	\
			ft_strtrim.c	ft_isdigit.c	ft_lstmap.c		ft_memdel.c		\
			ft_putendl.c	ft_rev.c 		ft_strdup.c		ft_strmap.c		\
			ft_strnew.c		ft_tolower.c 	ft_isprint.c	ft_lstnew.c		\
			ft_memmove.c	ft_putendl_fd.c	ft_strcat.c		ft_strequ.c		\
			ft_strmapi.c	ft_strnstr.c	ft_toupper.c	ft_atoi.c		\
			ft_itoa.c		ft_memalloc.c	ft_memndup.c 	ft_putnbr.c		\
			ft_strchr.c		ft_striter.c	ft_strncat.c 	ft_strrchr.c	\
			get_next_line.c ft_bzero.c		ft_lstadd.c		ft_memccpy.c	\
			ft_memset.c		ft_putnbr_fd.c	ft_strclr.c		ft_striteri.c	\
			ft_strncmp.c 	ft_strsplit.c 	ft_isalnum.c	ft_lstdel.c		\
			ft_memchr.c		ft_nrev.c		ft_putstr.c		ft_strcmp.c		\
			ft_strjoin.c	ft_strncpy.c 	ft_strstr.c 	ft_isalpha.c	\
			ft_lstdelone.c	ft_memcmp.c		ft_putchar.c	ft_putstr_fd.c	\
			ft_strcpy.c		ft_strlcat.c	ft_strndup.c	ft_strsub.c

O_FILES=$(C_FILES:.c=.o)

NAME = libft.a

all : $(NAME)

$(NAME) : $(O_FILES)
	ar rc $(NAME) $(O_FILES)
	ranlib $(NAME)

$(O_FILES) : %.o : %.c $(HEADER)
	gcc -Werror -Wall -Wextra -c $<
	
clean:
	rm -rf $(O_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all
