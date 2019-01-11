# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/28 17:00:59 by mpopovyc          #+#    #+#              #
#    Updated: 2018/07/23 20:16:59 by mpopovyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all fclean clean re 

NAME = lem-in

MAIN = $(addprefix src/, main.c init.c lstmanage.c push_back.c find_ways.c \
		errors.c rooms.c links.c components.c printer.c manage_rooms.c \
		move_ants.c validation.c)

OBJ = $(MAIN:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEADER = ./inc/lem.h

all : $(NAME)

$(NAME) : $(MAIN) $(HEADER)
	make -C libft/
	gcc $(FLAGS) -Llibft/ -lft -I ./inc $(MAIN) -o $(NAME)

%.o : %.c
	gcc -c -o $@ $< $(FLAGS) -I./inc

clean :
	@rm -rf $(OBJ)
	@rm -rf $(main)
	make -C libft/ clean
fclean : clean
	rm -rf $(NAME) 
	make -C libft/ fclean 

re : fclean all
