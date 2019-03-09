/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:14:06 by sunakim           #+#    #+#             */
/*   Updated: 2018/11/14 11:49:21 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	i = 0;
	while (*((unsigned char*)s1 + i) == *((unsigned char*)s2 + i) && i < n - 1)
		i++;
	if (*((unsigned char*)s1 + i) == *((unsigned char*)s2 + i))
		return (0);
	if (*((unsigned char*)s1 + i) != *((unsigned char*)s2 + i))
		return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
	return (0);
}
