/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:47:43 by sunakim           #+#    #+#             */
/*   Updated: 2019/02/26 13:12:40 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define ABS(x) ((x) < 0 ? -(x) : (x))

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_attack
{
	int x;
	int y;
	int tmp_x;
	int tmp_y;
}				t_attack;

typedef struct	s_game
{
	int			i;
	int			j;
	int			m;
	int			n;
	int			cnt;
	int			x;
	int			y;
	int			sw;
	char		p;
	char		r;
	int			pl[2];
	char		**b;
}				t_game;

typedef struct	s_coord
{
	int			x;
	int			y;
	int			i;
	int			sign;
	int			tmp_x;
	int			tmp_y;
}				t_coord;

typedef struct	s_piece
{
	int			x;
	int			y;
	int			cnt;
	int			tmp_x;
	int			tmp_y;
	int			plat[2];
	char		**piece;
}				t_piece;

int				parser(int fd, t_game *game, t_piece *p);
int				parse_piece(int fd, t_piece *p);
char			*find_line(char *find, int fd, int size);
int				find_player(char *line, t_game *game);
int				ft_error(void);
int				solver(t_game *game, t_piece *p, t_coord *ret, t_attack *r);
void			print_ret(t_piece *pc, t_coord *coord);
int				winner(t_game *game, t_attack *r, t_coord *ret, t_piece *p);

#endif
