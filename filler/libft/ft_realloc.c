/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:45:29 by sunakim           #+#    #+#             */
/*   Updated: 2018/12/12 12:46:40 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	int		i;
	void	*tmp;

	i = 0;
	if (size == 0)
		free(ptr);
	if (ptr == NULL)
	{
		ptr = malloc(size);
		return (ptr);
	}
	else
	{
		tmp = ft_memalloc(size);
		free(ptr);
		return (tmp);
	}
}
