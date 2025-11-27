/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 07:11:48 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/23 19:52:41 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	index_of(t_position p, t_solong *game)
{
	return ((size_t)p.y * (size_t)game->m_width + (size_t)p.x);
}

int	in_bounds(t_position pos, t_solong *game)
{
	return (pos.y >= 0 && pos.y < game->m_height
		&& pos.x >= 0 && pos.x < game->m_width);
}

int	is_walkable(t_position pos, t_solong *game)
{
	return (game->map[pos.y][pos.x] != '1');
}

static void	dfs_check(t_solong *game, t_position pos,
		char *visited, int *exit)
{
	t_position	next_pos;

	if (!in_bounds(pos, game))
		return ;
	if (!is_walkable(pos, game))
		return ;
	if (visited[index_of(pos, game)])
		return ;
	visited[index_of(pos, game)] = 1;
	if (game->map[pos.y][pos.x] == 'C')
		game->c_collected++;
	if (game->map[pos.y][pos.x] == 'E')
		*exit = 1;
	next_pos.x = pos.x + -1;
	next_pos.y = pos.y;
	dfs_check(game, next_pos, visited, exit);
	next_pos.x = pos.x + 1;
	dfs_check(game, next_pos, visited, exit);
	next_pos.x = pos.x;
	next_pos.y = pos.y + -1;
	dfs_check(game, next_pos, visited, exit);
	next_pos.y = pos.y + 1;
	dfs_check(game, next_pos, visited, exit);
}

int	find_path_to_exit_with_all_c(t_solong *game)
{
	char	*visited;
	int		exit;

	visited = ft_calloc(game->m_width * game->m_height, sizeof(char));
	if (!visited)
		return (0);
	exit = 0;
	dfs_check(game, game->player_pos, visited, &exit);
	free(visited);
	if (!(game->c_collected == game->c_total_coll) || !exit)
		return (0);
	game->c_collected = 0;
	return (1);
}
