/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:24:55 by sunakim           #+#    #+#             */
/*   Updated: 2019/03/08 18:37:57 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			find_attack(t_game *game, t_attack *r)
{
	int		i;
	int		a;
	int		b;
	char	attack;

	i = 0;
	(game->p == 'o') ? (attack = 'X') : (0);
	(game->p == 'x') ? (attack = 'O') : (0);
	b = 0;
	while (game->b[b] != NULL)
	{
		a = 0;
		while (game->b[b][a] != '\0')
		{
			if (game->b[b][a] == attack || game->b[b][a] == attack + 32)
			{
				r->x = a;
				r->y = b;
				return (1);
			}
			a++;
		}
		b++;
	}
	return (-1);
}

int			find_attack_bottom(t_game *game, t_attack *r)
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
				return (1);
			}
			a--;
		}
		b--;
	}
	return (-1);
}

int			find_attack_right(t_game *game, t_attack *r)
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

int			winner(t_game *game, t_attack *r, t_coord *ret, t_piece *p)
{
	int a;
	int b;

	find_attack_coord(game, r, ret);
	a = ABS(r->x - ret->tmp_x) + ABS(r->y - ret->tmp_y);
	b = ABS(r->x - ret->x) + ABS(r->y - ret->y);
	if (a < b)
	{
		ret->x = ret->tmp_x;
		ret->y = ret->tmp_y;
		p->x = p->tmp_x;
		p->y = p->tmp_y;
	}
	return (0);
}
