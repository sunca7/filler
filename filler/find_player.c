/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:12:54 by sunakim           #+#    #+#             */
/*   Updated: 2019/03/01 17:54:49 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	find_end(char *line, int i)
{
	while (line[i] != '\0')
		i++;
	return (i);
}

int			find_player(char *line, t_game *game)
{
	int i;

	i = 11;
	if (line == NULL)
		return (-1);
	if (ft_atoi(&(line[10])) == 1)
	{
		i = find_end(line, i);
		if ((ft_strncmp(&(line[i - 15]), "sunakim.filler", 14)) == 0)
		{
			game->p = 'o';
			free(line);
			return (1);
		}
	}
	else if (ft_atoi(&(line[10])) == 2)
	{
		i = find_end(line, i);
		if ((ft_strncmp(&(line[i - 15]), "sunakim.filler", 14)) == 0)
		{
			game->p = 'x';
			free(line);
			return (1);
		}
	}
	free(line);
	return (-1);
}
