/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:16:07 by sunakim           #+#    #+#             */
/*   Updated: 2018/11/14 11:40:47 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (*((char *)src + i) == (char)c)
		{
			*((char *)dst + i) = *((char *)src + i);
			return (dst + i + 1);
		}
		*((char *)dst + i) = *((char *)src + i);
		i++;
	}
	return (NULL);
}
