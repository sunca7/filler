/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:47:11 by sunakim           #+#    #+#             */
/*   Updated: 2019/03/11 11:57:58 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	valid_char(t_game *game)
{
	int a;
	int b;

	a = 0;
	a = 0;
	while (game->b[a] != NULL)
	{
		b = 0;
		while (game->b[a][b] != '\0')
		{
			if (!(game->b[a][b] == 'o' || game->b[a][b] == 'O' ||
				game->b[a][b] == 'X' || game->b[a][b] == 'x' ||
					game->b[a][b] == '.'))
				return (-1);
			b++;
		}
		a++;
	}
	return (1);
}

static int	find_coord(t_game *game)
{
	int		a;
	int		b;
	char	player;

	(game->p == 'o') ? (player = 'O') : (0);
	(game->p == 'x') ? (player = 'X') : (0);
	a = 0;
	while (game->b[a] != NULL)
	{
		b = 0;
		while (game->b[a][b] != '\0')
		{
			if (game->b[a][b] == player || game->b[a][b] == player - 32)
			{
				game->x = b;
				game->y = a;
				return (1);
			}
			b++;
		}
		a++;
	}
	return (-1);
}

static int	find_map(int fd, char *line, t_game *g)
{
	int i;

	if (line == NULL)
		return (-1);
	if (!(g->b = (char **)ft_memalloc(sizeof(char*) * ((g->pl[0]) + 1))))
		return (-1);
	i = 0;
	while (i < g->pl[0])
	{
		if (i != 0)
		{
			if (get_next_line(fd, &line) < 0)
				return (free_line(line));
		}
		if (line != NULL && (ft_strlen(line) == (size_t)(g->pl[1] + 4)))
		{
			if (!(g->b[i] = ft_strdup(&(line[4]))))
				return (-1);
			free(line);
		}
		else
			return (free_line(line));
		i++;
	}
	return (1);
}

int			parser(int fd, t_game *game, t_piece *p)
{
	(game->p == 'o') ? (game->r = 'x') : (0);
	(game->p == 'x') ? (game->r = 'o') : (0);
	if ((find_map(fd, find_line("000", fd), game)) != 1)
		return (-1);
	if ((find_coord(game)) != 1)
		return (-1);
	if ((valid_char(game) != 1))
		return (-1);
	if ((parse_piece(fd, p)) != 1)
		return (-1);
	return (1);
}
