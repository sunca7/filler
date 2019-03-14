/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:17:57 by sunakim           #+#    #+#             */
/*   Updated: 2018/11/21 15:32:43 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	result;

	if (s1 == NULL && s2 == NULL && n >= 1)
		return (1);
	if (!s1 || !s2)
		return (0);
	result = ft_strncmp(s1, s2, n);
	if (result == 0)
		return (1);
	else
		return (0);
}
