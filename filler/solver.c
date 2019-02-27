/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:31:30 by sunakim           #+#    #+#             */
/*   Updated: 2019/02/27 11:05:58 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	valid_map(t_game *g, t_coord *ret, t_piece *p)
{
	int a;
	int b;

	b = 0;
	while (b < p->plat[0])
	{
		a = 0;
		while (a < p->plat[1])
		{
			if ((p->piece[b][a] == '*') && (ret->tmp_y - p->tmp_y + b < 0 ||
				ret->tmp_x - p->tmp_x + a < 0 || ret->tmp_y - p->tmp_y + b >=
				g->pl[0] || ret->tmp_x - p->tmp_x + a >= g->pl[1]))
				return (-1);
			a++;
		}
		b++;
	}
	return (1);
}

static int	one(t_game *g, t_coord *ret, t_piece *p)
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
				{
						g->cnt++;
						//printf("ret->tmp_x %d  ret->tmp_y %d\n", ret->tmp_x, ret->tmp_y);
						//printf("cnt: %d\n", g->cnt);
				}
			else if (p->piece[g->m][g->n] == '*' && (g->b[ret->tmp_y - p->tmp_y
				+ g->m][ret->tmp_x - p->tmp_x + g->n] == g->r || g->b[ret->tmp_y
				- p->tmp_y + g->m][ret->tmp_x - p->tmp_x + g->n] == g->r - 32))
				{
					//printf("down \n");
					ret->sign = -1;
					return (-1);
				}
			g->n++;
		}
		g->m++;
	}
	if (g->cnt == 1)
	{
	//	printf("cnt 1 :ret->tmp_x %d  ret->tmp_y %d\n", ret->tmp_x, ret->tmp_y);
		return (1);
	}
	return (-1);
}

static int	tetro_valid(t_game *g, t_coord *ret, t_piece *p, t_attack *r)
{
	g->i = 0;
	while (g->i < g->pl[0])
	{
		g->j = 0;
		while (g->j < g->pl[1])
		{
			if (g->b[g->i][g->j] == g->p || g->b[g->i][g->j] == g->p - 32)
			{
				if (g->j - p->tmp_x >= 0 && g->i - p->tmp_y >= 0 && g->j +
				(p->plat[1] - p->tmp_x - 1) < g->pl[1] && g->i + (p->plat[0]
				- p->tmp_y - 1) < g->pl[0])
				{
					ret->tmp_x = g->j;
					ret->tmp_y = g->i;
					if ((valid_map(g, ret, p) == 1) && (one(g, ret, p) == 1))
						winner(g, r, ret, p);
				}
			}
			g->j++;
		}
		g->i++;
	}
	if (ret->tmp_x == -100 && ret->tmp_y == -100)
		return (0);
	return (1);
}

static int	piece_valid(t_game *g, t_coord *ret, t_piece *p, t_attack *r)
{
	int a;
	int b;

	ret->sign = 0;
	b = 0;
	while (b < p->plat[0])
	{
		a = 0;
		while (a < p->plat[1])
		{
			if (p->piece[b][a] == '*')
			{
				p->tmp_x = a;
				p->tmp_y = b;
				tetro_valid(g, ret, p, r);
			}
			a++;
		}
		b++;
	}
	if ((ret->x == -100) && (ret->y == -100))
		return (0);
	return (1);
}

int			solver(t_game *g, t_piece *p, t_coord *ret, t_attack *r)
{
	ret->x = -100;
	ret->y = -100;
	ret->tmp_x = 0;
	ret->tmp_y = 0;
	p->tmp_x = 0;
	p->tmp_x = 0;
	p->x = 0;
	p->y = 0;
	if (piece_valid(g, ret, p, r) == 1)
		return (1);
	else
	{
		return (-1);
	}
}
