/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:39:13 by sunakim           #+#    #+#             */
/*   Updated: 2018/11/21 15:03:41 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int i;

	if (!tab || !f)
		return ;
	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
	return ;
}
