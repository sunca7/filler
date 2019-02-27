/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:26:13 by sunakim           #+#    #+#             */
/*   Updated: 2018/11/21 15:12:11 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_params(int argc, char **argv)
{
	int a;
	int b;

	a = 1;
	if (argc > 0)
	{
		while (a < argc)
		{
			b = 0;
			while (argv[a][b])
			{
				ft_putchar(argv[a][b]);
				b++;
			}
			ft_putchar('\n');
			a++;
		}
	}
	return ;
}
