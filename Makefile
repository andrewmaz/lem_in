# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amazurok <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/23 11:59:18 by amazurok          #+#    #+#              #
#    Updated: 2018/03/23 16:46:32 by amazurok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = ft_add.c ft_addit_func.c ft_del.c ft_errors.c ft_help.c ft_int_operat.c \
		ft_is_in.c ft_lee_algor.c ft_new.c ft_output.c ft_read.c ft_read2.c \
		ft_read_flag.c ft_road.c ft_search.c ft_valid_link.c main.c

OSRC = $(patsubst %.c, %.o, $(SRC))

MLIB = make -C libftprintf

LIB = libftprintf/libftprintf.a

all: $(NAME)

$(NAME): $(SRC)
	$(MLIB) 
	gcc -Wall -Wextra -Werror $(SRC) $(LIB) -o $(NAME)
	
clean:
	rm -f $(OBJ)
	$(MLIB) clean

fclean: clean
	rm -f $(NAME_PS) $(NAME_CH)
	$(MLIB) fclean

re: fclean all