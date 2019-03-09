/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:56:33 by lsimanau          #+#    #+#             */
/*   Updated: 2018/11/18 12:11:20 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;

	i = 0;
	while (n > 0 && ((unsigned char*)s)[i] != (unsigned char)c)
	{
		n--;
		i++;
	}
	if (n == 0)
		return (NULL);
	if (((unsigned char*)s)[i] == (unsigned char)c)
		return ((void*)&s[i]);
	return (NULL);
}
