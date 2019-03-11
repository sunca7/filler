/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:12:54 by sunakim           #+#    #+#             */
/*   Updated: 2019/03/11 10:10:56 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			find_player(char *line, t_game *game)
{
	if (line == NULL)
		return (-1);
	if (ft_atoi(&(line[10])) == 1)
	{
		if ((ft_strstr(line, "sunakim.filler")) != NULL)
		{
			game->p = 'o';
			free(line);
			return (1);
		}
	}
	else if (ft_atoi(&(line[10])) == 2 && line[13] != '\0')
	{
		if ((ft_strstr(line, "sunakim.filler")) != NULL)
		{
			game->p = 'x';
			free(line);
			return (1);
		}
	}
	free(line);
	return (-1);
}
