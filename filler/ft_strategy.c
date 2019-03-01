/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:24:55 by sunakim           #+#    #+#             */
/*   Updated: 2019/03/01 15:59:23 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	find_attack(t_game *game, t_attack *r)
{
	int		i;
	int		a;
	int		b;
	char	attack;

	i = 0;
	(game->p == 'o') ? (attack = 'X') : (0);
	(game->p == 'x') ? (attack = 'O') : (0);
	a = 0;
	while (game->b[a] != NULL)
	{
		b = 0;
		while (game->b[a][b] != '\0')
		{
			if (game->b[a][b] == attack || game->b[a][b] == attack + 32)
			{
				r->x = b;
				r->y = a;
			//	printf("sw: %d\n", game->sw);
			//	printf("r->x : %d\n", r->x);
			//	printf("r->y : %d\n", r->y);
				return (1);
			}
			b++;
		}
		a++;
	}
	return (-1);
}

static int	find_attack_bottom(t_game *game, t_attack *r)
{
	int		a;
	int		b;
	char	attack;

	a = 0;
	b = 0;
	(game->p == 'o') ? (attack = 'X') : (0);
	(game->p == 'x') ? (attack = 'O') : (0);
	b = game->pl[0] - 1;
	while (b >= 0)
	{
		a = game->pl[1] - 1;
		while (a >= 0)
		{
			if (game->b[b][a] == attack || game->b[b][a] == attack + 32)
			{
				r->x = a;
				r->y = b;
			//	printf("sw: %d\n", game->sw);
			//	printf("r->x : %d\n", r->x);
			//	printf("r->y : %d\n", r->y);
				return (1);
			}
			a--;
		}
		b--;
	}
	return (-1);
}

static int	find_attack_right(t_game *game, t_attack *r)
{
	int		a;
	int		b;
	char	attack;

	a = 0;
	b = 0;
	(game->p == 'o') ? (attack = 'X') : (0);
	(game->p == 'x') ? (attack = 'O') : (0);
	a = game->pl[1] - 1;
	while (a >= 0)
	{
		b = game->pl[0] - 1;
		while (b >= 0)
		{
			if (game->b[b][a] == attack || game->b[b][a] == attack + 32)
			{
				r->x = a;
				r->y = b;
			//	printf("sw: %d\n", game->sw);
			//	printf("r->x : %d\n", r->x);
			//	printf("r->y : %d\n", r->y);
				return (1);
			}
			b--;
		}
		a--;
	}
	return (-1);
}

static int	find_attack_left(t_game *game, t_attack *r)
{
	int		a;
	int		b;
	char	attack;

	a = 0;
	b = 0;
	(game->p == 'o') ? (attack = 'X') : (0);
	(game->p == 'x') ? (attack = 'O') : (0);
	a = 0;
	while (a < game->pl[1])
	{
		b = game->pl[0] - 1;
		while (b >= 0)
		{
			if (game->b[b][a] == attack || game->b[b][a] == attack + 32)
			{
				r->x = a;
				r->y = b;
			//	printf("sw: %d\n", game->sw);
			//	printf("r->x : %d\n", r->x);
			//	printf("r->y : %d\n", r->y);
				return (1);
			}
			b--;
		}
		a++;
	}
	return (-1);
}

static void	find_attack_middle(t_game *game, t_attack *r)
{
	r->x = game->pl[1] / 2;
	r->y = game->pl[0] / 2;
}

int			winner(t_game *game, t_attack *r, t_coord *ret, t_piece *p)
{
	int a;
	int b;

	if ((game->p == 'x') || ((game->sw % 4 == 1) && (ret->zero != 1)))
		find_attack(game, r);
	else if ((game->p == 'o') || ((game->sw % 4 == 2) && (ret->zero != 2)))
		find_attack_bottom(game, r);
	else if ((game->p == 'o') || (game->sw % 4 == 3 && (ret->zero != 3)))
		find_attack_right(game, r);
	else if ((game->p == 'x') || (game->sw % 4 == 0 && (ret->zero != 4)))
		find_attack_left(game, r);
	else
		find_attack_middle(game, r);
	a = ABS(r->x - ret->tmp_x) + ABS(r->y - ret->tmp_y); // new
	b = ABS(r->x - ret->x) + ABS(r->y - ret->y);
//	printf("a: %d  b: %d\n", a, b);
//	printf("p x: %d  y: %d\n", p->x, p->y);
//	printf("r->x %d  r->y %d\n", r->x, r->y);
//	printf("ret->x %d  ret->y %d\n", ret->x, ret->y);
//	printf("ret->tmp_x %d  ret->tmp_y %d\n", ret->tmp_x, ret->tmp_y);
	if (a < b)
	{
        ret->x = ret->tmp_x;
        ret->y = ret->tmp_y;
	    p->x = p->tmp_x;
	    p->y = p->tmp_y;
 	}
	return (0);
}
