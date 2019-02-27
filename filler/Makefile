# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/05 15:55:57 by sunakim           #+#    #+#              #
#    Updated: 2019/02/25 20:07:49 by sunakim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sunakim.filler

SRCS = 	main.c    \
		parser.c 	\
		parse_piece.c \
		find_line.c 	\
		find_player.c 	\
		ft_error.c 	\
		solver.c	\
		print_ret.c	\
		ft_strategy.c

OBJ = $(SRCS:%.c=%.o)

INCLUDES = -I libft/includes

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	gcc $(FLAGS) $(INCLUDES) -L ./libft -lft -o $(NAME) $(OBJ)

 %.o : %.c
	gcc $(FLAGS) $(INCLUDES) -c $<

libft/libft.a:
	make -C libft
clean:
	make -C libft clean
	rm -f *.o

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
