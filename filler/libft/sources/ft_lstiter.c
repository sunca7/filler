/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:55:41 by lsimanau          #+#    #+#             */
/*   Updated: 2018/11/18 12:14:58 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*next_node;

	if (!(lst))
		return ;
	if (!(f))
		return ;
	while (lst)
	{
		next_node = lst->next;
		f(lst);
		lst = next_node;
	}
}
