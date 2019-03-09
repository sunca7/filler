/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 21:28:28 by lsimanau          #+#    #+#             */
/*   Updated: 2018/11/16 18:40:23 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		n;
	int		j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	n = 0;
	if (haystack[n] == '\0')
		return (NULL);
	while (haystack[n] != '\0' && (int)len > 0)
	{
		j = (int)len;
		while (haystack[n + i] == needle[i] && needle[i] != '\0' && j > 0)
		{
			i++;
			j--;
		}
		if (needle[i] == '\0')
			return (&((char *)haystack)[n]);
		i = 0;
		n++;
		len--;
	}
	return (NULL);
}
