/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:06:50 by lsimanau          #+#    #+#             */
/*   Updated: 2018/11/14 15:52:11 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst,
		const void *src, int c, size_t n)
{
	int		i;

	i = 0;
	while (n > 0 && ((unsigned char*)src)[i] != (unsigned char)c)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		i++;
		n--;
	}
	if (n == 0)
		return (NULL);
	if (((unsigned char*)src)[i] == (unsigned char)c)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		return (&dst[i + 1]);
	}
	return (NULL);
}
