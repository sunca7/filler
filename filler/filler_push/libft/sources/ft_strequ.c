/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:06:22 by lsimanau          #+#    #+#             */
/*   Updated: 2018/11/16 17:10:41 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	if (!(s1))
		return (0);
	if (!(s2))
		return (0);
	i = ft_strcmp(s1, s2);
	if (i == 0)
		return (1);
	return (0);
}
