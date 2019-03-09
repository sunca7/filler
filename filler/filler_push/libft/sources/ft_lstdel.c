/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 13:21:42 by lsimanau          #+#    #+#             */
/*   Updated: 2018/11/17 17:12:30 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **current_node, void (*del)(void *, size_t))
{
	t_list *next_node;

	if (current_node == 0)
		return ;
	while (*current_node)
	{
		next_node = (*current_node)->next;
		ft_lstdelone(current_node, del);
		*current_node = next_node;
	}
}
