/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:42:01 by sunakim           #+#    #+#             */
/*   Updated: 2018/11/21 15:11:05 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sort_params(char **argv)
{
	int		i;
	char	*tmp;

	i = 1;
	while (argv[i + 1])
	{
		if (ft_strcmp(*(argv + i), *(argv + i + 1)) > 0)
		{
			tmp = *(argv + i);
			*(argv + i) = *(argv + i + 1);
			*(argv + i + 1) = tmp;
			i = 1;
		}
		else
			i++;
	}
	return (argv);
}
