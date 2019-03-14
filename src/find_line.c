/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 19:39:08 by sunakim           #+#    #+#             */
/*   Updated: 2019/03/11 10:34:29 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*find_line(char *find, int fd)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line && ft_strstr(line, find) != NULL)
		{
			return (line);
		}
		free(line);
	}
	if (ret <= 0)
		return (NULL);
	free(line);
	return (NULL);
}
