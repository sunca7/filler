/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:06:49 by lsimanau          #+#    #+#             */
/*   Updated: 2018/11/18 12:05:55 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current_node;
	t_list	*head;

	if (!lst)
		return (NULL);
	if (!(f))
		return (NULL);
	head = f(lst);
	current_node = head;
	lst = lst->next;
	while (lst)
	{
		if (!(current_node->next = f(lst)))
			return (NULL);
		current_node = current_node->next;
		lst = lst->next;
	}
	return (head);
}
