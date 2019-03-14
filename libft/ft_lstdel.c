/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:40:32 by sunakim           #+#    #+#             */
/*   Updated: 2018/11/15 17:22:47 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list **tmp;

	if (!(alst && del))
		return ;
	while (*alst != NULL)
	{
		tmp = &((*alst)->next);
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = *tmp;
	}
	*alst = NULL;
	return ;
}
