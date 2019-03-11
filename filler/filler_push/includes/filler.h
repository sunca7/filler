/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:47:43 by sunakim           #+#    #+#             */
/*   Updated: 2019/03/11 10:33:50 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define ABS(x) ((x) < 0 ? -(x) : (x))
# define MIN(x, y) (x <= y ? x)

# include "libft.h"
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
	int		i;
	int		j;
	int		m;
	int		n;
	int		cnt;
	int		x;
	int		y;
	int		first_x;
	int		sw;
	int		t;
	char	p;
	char	r;
	int		pl[2];
	char	**b;
}				t_game;

typedef struct	s_coord
{
	int		x;
	int		y;
	int		i;
	int		sign;
	int		one;
	int		two;
	int		thr;
	int		top;
	int		bottom;
	int		mid;
	int		right;
	int		left;
	int		four;
	int		tmp_x;
	int		tmp_y;
}				t_coord;

typedef struct	s_piece
{
	int		x;
	int		y;
	int		cnt;
	int		tmp_x;
	int		tmp_y;
	int		plat[2];
	char	**piece;
}				t_piece;

int				parser(int fd, t_game *game, t_piece *p);
int				parse_piece(int fd, t_piece *p);
char			*find_line(char *find, int fd);
int				find_player(char *line, t_game *game);
int				ft_error(void);
int				free_line(char *line);
void			find_attack_middle(t_game *game, t_attack *r);
int				find_attack_right_top(t_game *game, t_attack *r);
int				find_attack_left(t_game *game, t_attack *r);
int				find_attack(t_game *game, t_attack *r);
int				find_attack_bottom(t_game *game, t_attack *r);
int				find_attack_right(t_game *game, t_attack *r);
int				find_attack_left_bottom(t_game *game, t_attack *r);
void			find_attack_coord(t_game *game, t_attack *r, t_coord *ret);
int				one(t_game *g, t_coord *ret, t_piece *p);
int				solver(t_game *game, t_piece *p, t_coord *ret, t_attack *r);
void			print_ret(t_piece *pc, t_coord *coord, t_game *game);
int				winner(t_game *game, t_attack *r, t_coord *ret, t_piece *p);

#endif
