/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:30:18 by lsimanau          #+#    #+#             */
/*   Updated: 2018/11/12 18:50:06 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		n;
	int		res;

	i = 0;
	while (dst[i] != '\0')
		i++;
	n = 0;
	while (src[n] != '\0')
		n++;
	if ((int)size >= i)
		res = i + n;
	else
		res = (int)size + n;
	n = 0;
	while ((int)size > i + 1 && src[n] != '\0')
	{
		dst[i] = src[n];
		i++;
		n++;
	}
	dst[i] = '\0';
	return (res);
}
