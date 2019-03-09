/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 10:38:36 by sunakim           #+#    #+#             */
/*   Updated: 2018/11/15 10:37:18 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt(int n)
{
	int				cnt;
	unsigned int	new_int;

	cnt = 0;
	if (n < 0)
	{
		cnt++;
		new_int = (unsigned int)(n * -1);
	}
	else
		new_int = n;
	while (new_int > 9)
	{
		new_int = new_int / 10;
		cnt++;
	}
	return (cnt);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		cnt;

	cnt = ft_cnt(n);
	if (!(s = (char*)malloc(sizeof(char) * (cnt + 2))))
		return (NULL);
	s[cnt + 1] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		s[cnt] = (n % 10) * -1 + '0';
		if (n < -9)
			n = -1 * (n / 10);
		cnt--;
	}
	while (n > 9)
	{
		s[cnt] = n % 10 + '0';
		n = n / 10;
		cnt--;
	}
	if (n >= 0 && n < 10)
		s[cnt] = n + '0';
	return (s);
}
