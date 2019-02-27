/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 19:28:40 by lsimanau          #+#    #+#             */
/*   Updated: 2018/11/17 19:28:59 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*curr;
	t_list	*prev;
	t_list	*after;

	curr = *begin_list;
	prev = NULL;
	while (curr != 0)
	{
		after = curr->next;
		curr->next = prev;
		prev = curr;
		curr = after;
	}
	*begin_list = prev;
}
