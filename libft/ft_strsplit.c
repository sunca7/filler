/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:19:07 by sunakim           #+#    #+#             */
/*   Updated: 2018/11/19 21:36:27 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_cnt(char const *s, char c)
{
	int i;
	int str_cnt;

	i = 0;
	str_cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			str_cnt++;
		i++;
	}
	return (str_cnt);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		i;
	int		start;
	int		end;
	int		j;

	i = 0;
	j = 0;
	if (!s || !c)
		return (0);
	if (!(array = (char **)malloc(sizeof(char *) * ((ft_str_cnt(s, c) + 1)))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		end = i;
		if (end > start)
			array[j++] = ft_strsub(s, start, end - start);
	}
	array[j] = NULL;
	return (array);
}
