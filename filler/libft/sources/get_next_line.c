/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:26:42 by lsimanau          #+#    #+#             */
/*   Updated: 2018/12/02 11:38:13 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		the_ifs(char **line, int j, char **ptr)
{
	if (j == -1)
	{
		*line = *ptr;
		return (1);
	}
	free(*ptr);
	return (0);
}

int		n_filler(char **ptr, char *buffer, int j, char **line)
{
	char	*temp2;
	char	*temp;

	if (j == -1)
	{
		if (!(temp = ft_strjoin(*ptr, buffer)))
			return (-1);
		free(*ptr);
		*ptr = temp;
		ft_strclr(buffer);
	}
	else
	{
		if (!(temp2 = ft_strsub(buffer, 0, j)))
			return (-1);
		if (!(temp = ft_strjoin(*ptr, temp2)))
			return (-1);
		free(temp2);
		*line = temp;
		ft_memmove(buffer, &buffer[j + 1], ft_strlen(buffer) - j);
		return (1);
	}
	return (0);
}

int		check_n(char *s, int a)
{
	int		i;

	i = 0;
	while (i < a && s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	int				n;
	int				j;
	static char		buffer[10240][BUFF_SIZE + 1];
	char			*ptr;
	int				ret;

	if (fd < 0 || line == NULL || fd >= 10240 || read(fd, buffer[fd], 0) < 0)
		return (-1);
	if (!(ptr = ft_strnew(0)))
		return (-1);
	n = 0;
	j = 0;
	while (buffer[fd][0] != '\0' || (n = read(fd, buffer[fd], BUFF_SIZE)) > 0)
	{
		if (n != 0)
			buffer[fd][n] = '\0';
		j = check_n(buffer[fd], BUFF_SIZE);
		ret = n_filler(&ptr, buffer[fd], j, line);
		if (ret == 1 || ret == -1)
		{
			free(ptr);
			return (ret);
		}
	}
	return (the_ifs(line, j, &ptr));
}
