/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:34:54 by sunakim           #+#    #+#             */
/*   Updated: 2019/03/07 20:06:38 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	check_zero(t_coord *ret, t_game *game)
{
	int a;
	int b;

	b = 0;
	while (game->b[b] != NULL)
	{
		a = 0;
		while (game->b[b][a] != '\0')
		{
			if (game->b[b][a] == game->p || game->b[b][a] == game->p - 32)
			{
				(a == 0) ? ret->left = 1 : 0;
				(a == game->pl[1] - 1) ? ret->right = 1 : 0;
				(b == 0) ? ret->top = 1 : 0;
				(b == game->pl[0] - 1) ? ret->bottom = 1 : 0;
				if (a <= ((game->pl[1] / 5) * 3))
					ret->mid = 1;
			}
			a++;
		}
		b++;
	}
}

void		print_ret(t_piece *p, t_coord *ret, t_game *game)
{
	int x;
	int y;

	check_zero(ret, game);
	x = ret->x - p->x;
	(x < 0) ? (x = 0) : (0);
	y = ret->y - p->y;
	(y < 0) ? (y = 0) : (0);
	if (ret->top == 1 && x <= game->pl[1] / 2)
		ret->one = 1;
	if (ret->bottom == 1 && (x >= game->pl[1] / 2))
		ret->two = 2;
	if (ret->top == 1 && (x >= game->pl[1] / 2))
		ret->thr = 3;
	if (ret->bottom == 1 && (x <= game->pl[1] / 2))
		ret->four = 4;
	ft_putnbr(y);
	ft_putstr(" ");
	ft_putnbr(x);
	ft_putstr("\n");
	return ;
}
