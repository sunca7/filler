/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:47:31 by lsimanau          #+#    #+#             */
/*   Updated: 2018/11/17 18:54:26 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_specialschars(char *str)
{
	int		n;

	n = 0;
	while (str[n] == ' ' || str[n] == '\n' || str[n] == '\t' ||
			str[n] == '\v' || str[n] == '\r' || str[n] == '\f')
		n++;
	return (n);
}

int				ft_atoi(const char *str)
{
	int		i;
	int		result;
	int		sign;

	sign = 1;
	result = 0;
	i = ft_specialschars((char *)str);
	if (str[i] == '-')
		sign = -sign;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
