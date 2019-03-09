/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:53:35 by lsimanau          #+#    #+#             */
/*   Updated: 2018/12/06 20:48:30 by lsimanau         ###   ########.fr       */
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
