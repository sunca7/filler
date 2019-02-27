/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:12:15 by lsimanau          #+#    #+#             */
/*   Updated: 2018/11/17 21:21:42 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_letter_alloc(char **array, int letters, int n)
{
	int		ch;

	array[n] = (char*)malloc(sizeof(char) * (letters + 1));
	if (!(array[n]))
	{
		ch = 0;
		while (ch <= n)
		{
			free(array[n]);
			n--;
		}
		return (0);
	}
	return (1);
}

static char		**ft_fill_array(char **array, const char *s, char c, int n)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			array[n][j] = s[i];
			i++;
			j++;
		}
		if (j > 0)
		{
			array[n][j] = '\0';
			n++;
			j = 0;
		}
	}
	return (array);
}

static int		ft_memoryalloc(char **array, char const *s, char c)
{
	int		i;
	int		n;
	int		letters;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		letters = 0;
		while (s[i] != c && s[i] != '\0')
		{
			letters++;
			i++;
		}
		if (letters > 0)
		{
			if (!ft_letter_alloc(array, letters, n))
				return (0);
			n++;
		}
		if (s[i] != '\0')
			i++;
	}
	array[n] = 0;
	return (1);
}

static int		ft_wordcount(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		words;
	int		send;

	send = 0;
	if (!(s))
		return (NULL);
	words = ft_wordcount(s, c);
	array = (char**)malloc(sizeof(char*) * (words + 1));
	if (!(array))
		return (NULL);
	if (!ft_memoryalloc(array, s, c))
		return (NULL);
	array = ft_fill_array(array, s, c, send);
	return (array);
}
