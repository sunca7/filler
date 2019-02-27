/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 12:02:37 by lsimanau          #+#    #+#             */
/*   Updated: 2018/11/18 12:02:40 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, t_list *new)
{
	t_list	*temp;

	if (!begin_list)
		return ;
	temp = *begin_list;
	if (*begin_list == 0)
	{
		*begin_list = new;
		return ;
	}
	while (temp != 0 && temp->next != 0)
		temp = temp->next;
	temp->next = new;
}
