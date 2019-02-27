/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:38:11 by lsimanau          #+#    #+#             */
/*   Updated: 2018/11/16 18:11:32 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		n;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	n = 0;
	if (haystack[n] == '\0')
		return (NULL);
	while (haystack[n] != '\0')
	{
		while (haystack[n + i] == needle[i] && needle[i] != '\0')
			i++;
		if (needle[i] == '\0')
			return (&((char *)haystack)[n]);
		i = 0;
		n++;
	}
	return (NULL);
}
