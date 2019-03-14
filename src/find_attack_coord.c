/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_attack_coord.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:00:00 by sunakim           #+#    #+#             */
/*   Updated: 2019/03/08 18:33:22 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		game_t_one(t_game *game, t_attack *r, t_coord *ret)
{
	if ((game->sw % 2 == 1) && ret->bottom != 1)
		find_attack_bottom(game, r);
	else if ((game->sw % 2 == 0) && ret->bottom != 1)
		find_attack_right(game, r);
	else if (ret->bottom == 1 && ret->left != 1)
		find_attack_left_bottom(game, r);
	else if (ret->bottom == 1 && ret->left == 1 && ret->top != 1)
		find_attack_right_top(game, r);
	else
	{
		r->x = game->pl[1] / 2;
		r->y = game->pl[0] / 4;
	}
}

static void		game_t_two(t_game *game, t_attack *r, t_coord *ret)
{
	if (ret->mid != 1)
		find_attack(game, r);
	else if (ret->mid == 1 && ret->top != 1)
	{
		r->x = game->pl[1] / 2;
		r->y = 0;
	}
	else if (ret->top == 1 && ret->bottom != 1)
		find_attack_left(game, r);
	else
	{
		r->x = 0;
		r->y = 0;
	}
}

static void		up_down(t_game *game, t_attack *r)
{
	if (game->sw == 1)
	{
		find_attack(game, r);
		if ((game->p == 'o' && game->x < r->x) || (game->p == 'x' &&
		game->x < r->x))
		{
			game->first_x = game->x;
			game->t = 1;
		}
		if ((game->p == 'x' && game->x > r->x) || (game->p == 'o' &&
		game->x > r->x))
			game->t = 2;
	}
}

void			find_attack_coord(t_game *game, t_attack *r, t_coord *ret)
{
	up_down(game, r);
	if (game->t == 1)
		game_t_one(game, r, ret);
	if (game->t == 2)
		game_t_two(game, r, ret);
}
