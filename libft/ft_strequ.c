/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:14:08 by sunakim           #+#    #+#             */
/*   Updated: 2018/11/21 15:33:53 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int result;

	if (s1 == NULL && s2 == NULL)
		return (1);
	if (!s1 || !s2)
		return (0);
	result = ft_strcmp(s1, s2);
	if (result == 0)
		return (1);
	else
		return (0);
}
