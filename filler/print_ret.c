/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:34:54 by sunakim           #+#    #+#             */
/*   Updated: 2019/02/28 18:27:12 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_ret(t_piece *p, t_coord *ret, t_game *game)
{
	int x;
	int y;

	x = ret->x - p->x;
	if (x < 0)
		x = 0;
	y = ret->y - p->y;
	if (y < 0)
		y = 0;
	if (y <= 2 && x <= 2)
		ret->zero = 1;
	if ((y >= game->pl[0] - 3) && (x >= game->pl[1] - 3))
		ret->zero = 2;
	if ((y <= 2) && (x >= game->pl[1] - 3))
		ret->zero = 3;
	if ((y >= game->pl[0] - 3) && (x <= 3))
		ret->zero = 4;
	ft_putnbr(y);
	ft_putstr(" ");
	ft_putnbr(x);
	ft_putstr("\n");
	return ;
}
