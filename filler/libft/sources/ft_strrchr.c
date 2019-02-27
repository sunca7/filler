/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:59:32 by lsimanau          #+#    #+#             */
/*   Updated: 2018/11/12 17:34:30 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*d;

	i = 0;
	d = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			d = &((char *)s)[i];
		i++;
	}
	if (s[i] == (char)c)
		return (&((char *)s)[i]);
	return (d);
}
