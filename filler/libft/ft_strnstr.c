/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:49:11 by sunakim           #+#    #+#             */
/*   Updated: 2018/11/20 15:59:37 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t a;
	size_t b;
	size_t str2end;
	size_t start;

	str2end = ft_strlen(str2);
	if (str2end == 0)
		return ((char *)str1);
	a = 0;
	start = 0;
	while (str1[a] != '\0' && a < len)
	{
		b = 0;
		while (str1[a] == str2[b] && str1[a] && str2[b] && a < len && b++ < len)
			a++;
		if (b == str2end && a <= len && b <= len)
			return ((char *)(str1 + a - str2end));
		else if (a < len)
			a = ++start;
	}
	return (NULL);
}
