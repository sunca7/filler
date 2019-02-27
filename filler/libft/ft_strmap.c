/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:58:07 by sunakim           #+#    #+#             */
/*   Updated: 2018/11/19 14:15:56 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		fi;
	char	*str;

	if (!(s && f))
		return (0);
	i = ft_strlen(s);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	fi = 0;
	while (s[fi] != '\0')
	{
		str[fi] = f(s[fi]);
		fi++;
	}
	return (str);
}
