/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:32:34 by sunakim           #+#    #+#             */
/*   Updated: 2018/11/11 14:45:56 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	tmp;
	char			c;

	tmp = 0;
	if (n >= 0)
		tmp = n;
	if (n < 0)
	{
		c = '-';
		write(fd, &c, 1);
		tmp = (unsigned int)(n * -1);
	}
	if (tmp > 9)
	{
		ft_putnbr_fd(tmp / 10, fd);
		c = tmp % 10 + '0';
		write(fd, &c, 1);
	}
	else
	{
		c = tmp + '0';
		write(fd, &c, 1);
	}
}
