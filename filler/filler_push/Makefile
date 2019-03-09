# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/05 15:55:57 by sunakim           #+#    #+#              #
#    Updated: 2019/03/08 15:29:40 by sunakim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sunakim.filler

SRCS	= 	main.c					\
			parser.c				\
			parse_piece.c			\
			find_line.c				\
			find_player.c			\
			ft_error.c				\
			solver.c				\
			print_ret.c				\
			ft_strategy.c			\
			find_attack_middle.c	\
			find_attack_coord.c		\
			free_line.c

INCLUDES =	./includes/filler.h \
        	./libft/includes/libft.h

OBJS = $(patsubst %.c,obj/%.o,$(SRCS))

CC = gcc

CFLAGS := $(FLAGS) -Wall -Wextra -Werror

INCLUDE_FOLDERS = -I./includes -I./libft/includes

LIBRARY_PATH = -Llibft

.PHONY: clean fclean re

.SUFFIXES: .c .o

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
		$(CC) $(CFLAGS) $(INCLUDE_FOLDERS) $(LIBRARY_PATH) -lft $(OBJS) -o $@

obj:
	mkdir -p obj

obj/%.o : src/%.c $(INCLUDES) | obj
		$(CC) $(CFLAGS) $(INCLUDE_FOLDERS) -c $< -o $@

libft/libft.a: libft/includes/libft.h
				make -C libft

clean:
		make -C libft clean
		rm -f $(OBJS)
		rm -rf obj

fclean: clean
		make -C libft fclean
		rm -f $(NAME)
	
re: 	fclean
		make all
