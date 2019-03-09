/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:05:29 by sunakim           #+#    #+#             */
/*   Updated: 2018/11/21 17:12:18 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	int		cnt;
	size_t	i;
	char	*str;

	cnt = ft_strlen(s1);
	if (!(str = (char *)malloc(sizeof(char) * (cnt + 1))))
		return (0);
	if (s1 == '\0')
	{
		*str = '\0';
		return (str);
	}
	i = 0;
	while (s1[i] && i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
