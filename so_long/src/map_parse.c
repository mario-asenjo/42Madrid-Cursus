/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:44:53 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/23 20:08:49 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_count_lines(char *filename)
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

static char	**efectuate_copy(int line_count, int fd, t_solong *game)
{
	int		i;
	char	*line;
	int		l_len;

	i = 0;
	while (i < line_count)
	{
		line = get_next_line(fd);
		l_len = (int)ft_strlen(line);
		if (l_len > 0 && line[l_len - 1] == '\n')
			line[l_len - 1] = '\0';
		if (line[0] == '\0' || line[0] == '\n')
			return (map_free(game), close(fd), free(line), NULL);
		game->map[i] = ft_strdup(line);
		if (!game->map[i])
			return (map_free(game), close(fd), free(line), NULL);
		free(line);
		i++;
	}
	return (game->map);
}

char	**map_copy(char *filename, int line_count, t_solong *game)
{
	int		fd;

	game->map = ft_calloc(line_count + 1, sizeof(char *));
	if (!game->map)
		return (NULL);
	game->map[line_count] = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(game->map), game->map = NULL, NULL);
	if (!efectuate_copy(line_count, fd, game))
		return (NULL);
	close(fd);
	return (game->map);
}

int	map_validate_aux(const t_solong *g)
{
	int	i;

	i = 0;
	while (i < g->m_width)
	{
		if (g->map[0][i] != '1' || g->map[g->m_height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < g->m_height)
	{
		if (g->map[i][0] != '1' || g->map[i][g->m_width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	line_check(char c, t_solong *game, t_map_vals *map_vals)
{
	if (!ft_iscinstr("01CEP", c))
		return (0);
	if (c == 'C')
		game->c_total_coll++;
	if (c == 'E' && !map_vals->e_flag)
	{
		map_vals->e_flag = 1;
		game->exit_pos.x = map_vals->col;
		game->exit_pos.y = map_vals->line;
	}
	else if (c == 'E')
		return (0);
	if (c == 'P' && !map_vals->p_flag)
	{
		map_vals->p_flag = 1;
		game->player_pos.x = map_vals->col;
		game->player_pos.y = map_vals->line;
	}
	else if (c == 'P')
		return (0);
	return (1);
}
