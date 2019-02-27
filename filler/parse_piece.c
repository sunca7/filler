/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:53:43 by sunakim           #+#    #+#             */
/*   Updated: 2019/02/26 12:18:11 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	count_star(t_piece *p)
{
	int a;
	int b;

	p->cnt = 0;
	b = 0;
	while (b < p->plat[0])
	{
		a = 0;
		while (a < p->plat[1])
		{
			if (p->piece[b][a] == '*')
			{
				p->cnt++;
			}
			a++;
		}
		b++;
	}
	if (p->cnt < 1)
		return (-1);
	return (1);
}

static int	valid_char(t_piece *p)
{
	int a;
	int b;

	a = 0;
	a = 0;
	while (p->piece[a] != NULL)
	{
		b = 0;
		while (p->piece[a][b] != '\0')
		{
			if (p->piece[a][b] != '*' && p->piece[a][b] != '.')
			{
				return (-1);
			}
			b++;
		}
		a++;
	}
	return (1);
}

static int	find_piece(int fd, t_piece *p)
{
	int		i;
	char	*line;

	p->piece = (char **)ft_memalloc(sizeof(char*) * ((p->plat[0]) + 1));
	i = 0;
	while (i < p->plat[0])
	{
		get_next_line(fd, &line);
		if (ft_strlen(line) != (size_t)(p->plat[1]))
		{
			free(line);
			return (-1);
		}
		p->piece[i] = ft_strdup(line);
		free(line);
		i++;
	}
	return (1);
}

static int	find_plat(char *line, t_piece *p)
{
	char *tmp;

	tmp = NULL;
	p->plat[0] = 0;
	p->plat[1] = 0;
	if (line[6] != '\0')
		p->plat[0] = ft_atoi(&(line[6]));
	else
	{
		free(line);
		return (-1);
	}
	tmp = ft_strchr(&(line[6]), ' ');
	if (tmp != NULL)
		p->plat[1] = ft_atoi(tmp);
	else
	{
		free(line);
		return (-1);
	}
	free(line);
	return (1);
}

int			parse_piece(int fd, t_piece *p)
{
	if ((find_plat(find_line("Piece ", fd, 6), p)) != 1)
		return (-1);
	if ((find_piece(fd, p)) != 1)
		return (-1);
	if ((valid_char(p)) != 1)
		return (-1);
	if ((count_star(p)) != 1)
		return (-1);
	return (1);
}
