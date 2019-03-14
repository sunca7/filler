/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:47:46 by sunakim           #+#    #+#             */
/*   Updated: 2018/11/19 22:19:10 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		j;
	char	*str;

	if (!s)
		return (0);
	while ((*s == ' ' || *s == '\n' || *s == '\t') && *s != '\0')
		s++;
	if (*s == '\0')
		str = ft_strnew(1);
	else
	{
		j = ft_strlen(s) - 1;
		while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && s[j] != '\0')
			j--;
		str = ft_strsub(s, 0, j + 1);
	}
	return (str);
}
