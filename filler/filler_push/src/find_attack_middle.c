/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_attack_middle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:33:02 by sunakim           #+#    #+#             */
/*   Updated: 2019/03/08 13:33:11 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	find_attack_middle(t_game *game, t_attack *r)
{
	r->x = game->pl[1] / 2;
	r->y = game->pl[0] / 2;
}

int		find_attack_right_top(t_game *game, t_attack *r)
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
		b = 0;
		while (game->b[b] != NULL)
		{
			if (game->b[b][a] == attack || game->b[b][a] == attack + 32)
			{
				r->x = a;
				r->y = b;
				return (1);
			}
			b++;
		}
		a--;
	}
	return (-1);
}

int		find_attack_left(t_game *game, t_attack *r)
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
		a = 0;
		while (a < game->pl[1])
		{
			if (game->b[b][a] == attack || game->b[b][a] == attack + 32)
			{
				r->x = a;
				r->y = b;
				return (1);
			}
			a++;
		}
		b--;
	}
	return (-1);
}

int		find_attack_left_bottom(t_game *game, t_attack *r)
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
				return (1);
			}
			b--;
		}
		a++;
	}
	return (-1);
}

int		one(t_game *g, t_coord *ret, t_piece *p)
{
	g->cnt = 0;
	g->m = 0;
	while (g->m < p->plat[0])
	{
		g->n = 0;
		while (g->n < p->plat[1])
		{
			if (p->piece[g->m][g->n] == '*' && (g->b[ret->tmp_y - p->tmp_y +
				g->m][ret->tmp_x - p->tmp_x + g->n] == g->p || g->b[ret->tmp_y
				- p->tmp_y + g->m][ret->tmp_x - p->tmp_x + g->n] == g->p - 32))
				g->cnt++;
			else if (p->piece[g->m][g->n] == '*' && (g->b[ret->tmp_y - p->tmp_y
				+ g->m][ret->tmp_x - p->tmp_x + g->n] == g->r || g->b[ret->tmp_y
				- p->tmp_y + g->m][ret->tmp_x - p->tmp_x + g->n] == g->r - 32))
			{
				ret->sign = -1;
				return (-1);
			}
			g->n++;
		}
		g->m++;
	}
	if (g->cnt == 1)
		return (1);
	return (-1);
}
