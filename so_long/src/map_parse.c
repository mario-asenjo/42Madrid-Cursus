/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:44:53 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/15 20:43:58 by masenjo          ###   ########.fr       */
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
	return (game->map);
}
