/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 19:32:59 by lsimanau          #+#    #+#             */
/*   Updated: 2018/11/17 19:33:02 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *begin_list)
{
	int i;

	i = 0;
	while (begin_list != 0)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}
