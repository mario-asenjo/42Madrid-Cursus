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
	int		l_len;

	game->map = ft_calloc(line_count + 1, sizeof(char *));
	if (!game->map)
		return (NULL);
	game->map[line_count] = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(game->map), game->map = NULL, NULL);
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
	close(fd);
	return (game->map);
}

static int map_validate_aux(t_solong *game)
{
	int	i;

	i = 0;
	while (i < game->m_width)
	{
		if (game->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->m_width)
	{
		if (game->map[game->m_height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->m_height)
	{
		if (game->map[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->m_height)
	{
		if (game->map[i][game->m_width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	map_validate(t_solong *game)
{
	int		line;
	int		col;
	int		e_flag;
	int		p_flag;

	if (game->m_height <= 3 || game->m_width <= 3)
		return (0);
	e_flag = 0;
	p_flag = 0;
	line = 0;
	while (game->m_height > line)
	{
		if ((int)ft_strlen(game->map[line]) != game->m_width)
			return (0);
		col = 0;
		while (game->m_width > col)
		{
			if (!ft_iscinstr("01CEP", game->map[line][col]))
				return (0);
			if (game->map[line][col] == 'C')
				game->c_total_coll++;
			if (game->map[line][col] == 'E' && !e_flag)
			{
				e_flag = 1;
				game->exit_pos.x = col;
				game->exit_pos.y = line;
			}
			else if (game->map[line][col] == 'E')
				return (0);
			if (game->map[line][col] == 'P' && !p_flag)
			{
				p_flag = 1;
				game->player_pos.x = col;
				game->player_pos.y = line; 
				ft_printf("Playerinital: x: %d, y: %d", col, line);
			}
			else if (game->map[line][col] == 'P')
				return (0);
			col++;
		}
		line++;
	}
	if (!map_validate_aux(game))
		return (0);
	return (e_flag && p_flag && game->c_total_coll > 0);
}

char	**map_load(char *filename, t_solong *game)
{
	int		line_count;

	game->map = NULL;
	game->m_height = 0;
	game->m_width = 0;
	line_count = map_count_lines(filename);
	if (line_count < 0)
		return (0);
	game->m_height = line_count;
	game->map = map_copy(filename, line_count, game);
	if (!game->map)
		return (0);
	game->m_width = ft_strlen(game->map[0]);
	game->c_total_coll = 0;
	game->player_pos.x = 0;
	game->player_pos.y = 0;
	if (!map_validate(game))
		return (0);
	ft_printf("dentro de map_load: mapa validado!\n");
	return (game->map);
}
