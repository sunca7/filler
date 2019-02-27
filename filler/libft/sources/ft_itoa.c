/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:12:29 by lsimanau          #+#    #+#             */
/*   Updated: 2018/11/16 18:44:38 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_string(long long hold, int len, char *str)
{
	if (hold >= 0)
	{
		str[len] = '\0';
		while (len > 0)
		{
			str[len - 1] = (hold % 10) + '0';
			hold = hold / 10;
			len--;
		}
	}
	if (hold < 0)
	{
		hold = -hold;
		str[len] = '\0';
		while (len > 1)
		{
			str[len - 1] = (hold % 10) + '0';
			hold = hold / 10;
			len--;
		}
		str[0] = '-';
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int			len;
	char		*str;
	long long	hold;
	long long	num;

	num = n;
	hold = num;
	if (num < 0)
	{
		num = -num;
		len = 2;
	}
	else
		len = 1;
	while (num >= 10)
	{
		num = num / 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (0);
	str = ft_string(hold, len, str);
	return (str);
}
