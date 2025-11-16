/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:44:53 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/15 21:17:38 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	map_count_lines(char *filename)
{
	int		line_count;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line_count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

static char	**map_copy(char *filename, int line_count, t_solong *game)
{
	char	*line;
	int		fd;
	int		i;

	game->map = (char **) malloc(sizeof(char *) * line_count);
	if (!game->map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	while (i < line_count)
	{
		line = get_next_line(fd);
		game->map[i] = ft_substr(line, 0, ft_strlen(line) - 1);
		free(line);
		i++;
	}
	close(fd);
	return (game->map);
}

int	map_validate(t_solong *game)
{
	int	line;
	int	col;
	int	e_flag;
	int	p_flag;

	e_flag = 0;
	p_flag = 0;
	line = 0;
	while (game->m_height > line)
	{
		col = 0;
		while (game->m_width > col)
		{
			if (!ft_iscinstr("01CEP", game->map[line][col]))
				return (0);
			if (game->map[line][col] == 'E' && !e_flag)
				e_flag = 1;
			else if (game->map[line][col] == 'E')
				return (0);
			if (game->map[line][col] == 'P' && !p_flag)
				p_flag = 1;
			else if (game->map[line][col] == 'P')
				return (0);
			col++;
		}
		line++;
	}
	if (!e_flag || !p_flag)
		return (0);
	return (1);
}

char	**map_load(char *filename, t_solong *game)
{
	int		line_count;

	line_count = map_count_lines(filename);
	if (line_count < 0)
		return (0);
	game->m_height = line_count;
	game->map = map_copy(filename, line_count, game);
	if (!game->map)
		return (0);
	game->m_width = ft_strlen(game->map[0]);
	if (!map_validate(game))
		return (0);
	return (game->map);
}
