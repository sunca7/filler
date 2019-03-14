/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:30:32 by sunakim           #+#    #+#             */
/*   Updated: 2018/11/19 16:38:40 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int a;
	int b;
	int str2end;
	int start;

	str2end = 0;
	while (str2[str2end])
		str2end++;
	if (str2end == 0)
		return ((char *)str1);
	a = 0;
	start = 0;
	while (str1[a])
	{
		b = 0;
		while (str1[a] == str2[b] && str1[a] && str2[b++])
			a++;
		if (b == str2end)
			return ((char *)(str1 + a - str2end));
		else
			a = ++start;
	}
	return (NULL);
}
