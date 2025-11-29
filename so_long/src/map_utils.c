/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 20:04:45 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/29 09:07:49 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_check_extension(char *filename)
{
	int	len;

	len = (int)ft_strlen(filename);
	if (len >= 4 && ft_strncmp(".ber",
			&filename[ft_strlen(filename) - 4], 4) == 0)
		return (1);
	return (0);
}

void	map_free(t_solong *game)
{
	int	line;

	line = 0;
	while (game->m_height > line)
	{
		if (game->map[line])
		{
			free(game->map[line]);
			game->map[line] = NULL;
		}
		line++;
	}
	free(game->map);
	game->map = NULL;
	game->m_height = 0;
	game->m_width = 0;
}

static void	load_enemies(t_solong *game)
{
	int	i;
	int	j;

	i = 0;
	game->enemy_count = 0;
	while (i < game->m_height)
	{
		j = 0;
		while (j < game->m_width)
		{
			if (game->map[i][j] == 'X' && game->enemy_count < MAX_ENEMIES)
			{
				game->enemies[game->enemy_count].pos.x = j;
				game->enemies[game->enemy_count].pos.y = i;
				game->enemies[game->enemy_count]
					.origin = game->enemies[game->enemy_count].pos;
				game->enemies[game->enemy_count].dirx = 1;
				game->enemy_count++;
			}
			j++;
		}
		i++;
	}
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
	load_enemies(game);
	return (game->map);
}

int	map_validate(t_solong *game)
{
	t_map_vals	map_vals;

	if (game->m_height <= 3 || game->m_width <= 3)
		return (0);
	map_vals.e_flag = 0;
	map_vals.p_flag = 0;
	map_vals.line = 0;
	while (game->m_height > map_vals.line)
	{
		if ((int)ft_strlen(game->map[map_vals.line]) != game->m_width)
			return (0);
		map_vals.col = 0;
		while (game->m_width > map_vals.col)
		{
			if (!line_check(game->map[map_vals.line][map_vals.col],
				game, &map_vals))
				return (0);
			map_vals.col++;
		}
		map_vals.line++;
	}
	if (!map_validate_aux(game))
		return (0);
	return (map_vals.e_flag && map_vals.p_flag && game->c_total_coll > 0);
}
