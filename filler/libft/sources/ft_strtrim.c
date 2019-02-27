/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:40:32 by lsimanau          #+#    #+#             */
/*   Updated: 2018/11/17 18:51:12 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_beginnum(char const *s)
{
	int		begin;

	begin = 0;
	while ((s[begin] == ' ' || s[begin] == '\n' || s[begin] == '\t') &&
			s[begin] != '\0')
		begin++;
	return (begin);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		begin;
	int		end;
	char	*str;

	if (!(s))
		return (NULL);
	begin = ft_beginnum(s);
	if (s[begin] == '\0')
	{
		if (!(str = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	end = ft_strlen(s);
	while (s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t')
		end--;
	if (!(str = (char*)malloc(sizeof(char) * (end - begin + 1 + 1))))
		return (NULL);
	i = 0;
	while (begin < end)
		str[i++] = s[begin++];
	str[i] = '\0';
	return (str);
}
