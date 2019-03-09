/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:55:07 by sunakim           #+#    #+#             */
/*   Updated: 2018/11/19 20:21:46 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t a;
	size_t b;

	a = ft_strlen(dst);
	b = ft_strlen(src);
	if (size <= a)
		return (b + size);
	else
	{
		i = 0;
		while (i < size - 1 - a && src[i] != '\0')
		{
			dst[i + a] = src[i];
			i++;
		}
		dst[a + i] = '\0';
		return (a + b);
	}
}
