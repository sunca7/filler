/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:34:54 by sunakim           #+#    #+#             */
/*   Updated: 2019/02/25 17:57:32 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_ret(t_piece *p, t_coord *ret)
{
	int x;
	int y;

	x = ret->x - p->x;
	if (x < 0)
		x = 0;
	y = ret->y - p->y;
	if (y < 0)
		y = 0;
	ft_putnbr(y);
	ft_putstr(" ");
	ft_putnbr(x);
	ft_putstr("\n");
	return ;
}
