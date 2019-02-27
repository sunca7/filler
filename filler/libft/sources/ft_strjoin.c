/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:58:21 by lsimanau          #+#    #+#             */
/*   Updated: 2018/11/16 20:51:18 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_whiles(char *str, char const *s1, char const *s2)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s1[i] != '\0')
	{
		str[n] = s1[i];
		n++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[n] = s2[i];
		n++;
		i++;
	}
	str[n] = '\0';
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!(s1))
		return (0);
	if (!(s2))
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(str))
		return (NULL);
	ft_whiles(str, s1, s2);
	return (str);
}
