/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:12:54 by sunakim           #+#    #+#             */
/*   Updated: 2019/03/07 11:52:39 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	find_end(char *line)
{
	int i;

	i = 11;
	while (line[i] != '\0')
		i++;
	return (i);
}

int			find_player(char *line, t_game *game)
{
	if (line == NULL)
		return (-1);
	if (ft_atoi(&(line[10])) == 1)
	{
		if ((ft_strncmp(&(line[(find_end(line)) - 15]), "sunakim.filler", 14))
			== 0)
		{
			game->p = 'o';
			free(line);
			return (1);
		}
	}
	else if (ft_atoi(&(line[10])) == 2)
	{
		if ((ft_strncmp(&(line[(find_end(line)) - 15]), "sunakim.filler", 14))
			== 0)
		{
			game->p = 'x';
			free(line);
			return (1);
		}
	}
	free(line);
	return (-1);
}
