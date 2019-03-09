/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:22:35 by lsimanau          #+#    #+#             */
/*   Updated: 2018/11/16 17:11:25 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;

	if (!(s1))
		return (0);
	if (!(s2))
		return (0);
	i = ft_strncmp(s1, s2, n);
	if (i == 0)
		return (1);
	return (0);
}
