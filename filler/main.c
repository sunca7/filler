/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:49:01 by sunakim           #+#    #+#             */
/*   Updated: 2019/02/28 17:55:39 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	find_plateau(char *line, t_game *game)
{
	char *tmp;

	tmp = NULL;
	game->pl[0] = 0;
	game->pl[1] = 0;
	if (line[8] != '\0')
		game->pl[0] = ft_atoi(&(line[8]));
	else
	{
		free(line);
		return (-1);
	}
	tmp = ft_strchr(&(line[8]), ' ');
	if (tmp != NULL)
		game->pl[1] = ft_atoi(tmp);
	else
	{
		free(line);
		return (-1);
	}
	free(line);
	return (1);
}

static void	free_malloc(t_game *game, t_piece *p)
{
	int i;

	i = 0;
	if (game->b)
	{
		while (i < game->pl[0])
		{
			free(game->b[i]);
			i++;
		}
		free(game->b);
		game->b = NULL;
	}
	i = 0;
	if (p->piece)
	{
		while (i < p->plat[0])
		{
			free(p->piece[i]);
			i++;
		}
		free(p->piece);
		p->piece = NULL;
	}
}

static void	free_init_info(t_game *game, t_piece *p, t_coord *ret)
{
	free_malloc(game, p);
	ret->x = -100;
	ret->y = -100;
	ret->tmp_x = 0;
	ret->tmp_y = 0;
	p->tmp_x = 0;
	p->tmp_x = 0;
	p->x = 0;
	p->y = 0;
}

static void	init_filler(t_game *game, t_piece *p, t_coord *ret, t_attack *r)
{
	ft_bzero(game, sizeof(t_game));
	ft_bzero(p, sizeof(t_piece));
	ft_bzero(ret, sizeof(t_coord));
	ft_bzero(r, sizeof(t_attack));
}

int			main(void)
{
	t_game		game;
	t_piece		p;
	t_coord		ret;
	t_attack	r;

	init_filler(&game, &p, &ret, &r);
	if ((find_player(find_line("$$$ exec p", 0, 10), &game)) != 1)
		return (0);
	if ((find_plateau(find_line("Plateau ", 0, 8), &game)) != 1)
		return (0);
	while (1)
	{
		game.sw++;
		free_init_info(&game, &p, &ret);
		if ((parser(0, &game, &p)) != 1)
			break ;
		if (solver(&game, &p, &ret, &r) == 1)
			print_ret(&p, &ret, &game);
		else
		{
			ft_putstr("0 0\n");
			break ;
		}
	}
	free_malloc(&game, &p);
	return (0);
}
