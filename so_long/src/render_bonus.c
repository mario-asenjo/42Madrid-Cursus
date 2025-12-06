/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:29:14 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/06 13:05:48 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "../include/so_long.h"

static void	draw_tile_aux(t_solong *game, char cell, int px, int py)
{
	void	*img;

	img = NULL;
	if (cell == 'C')
	{
		if (game->coin_anim.count > 0)
			img = game->coin_anim.frames[game->coin_anim.cur].img_ptr;
		else
			img = game->coin.img_ptr;
		mlx_put_image_to_window(game->connection, game->window,
			img, px, py);
	}
	if (cell == 'X')
		mlx_put_image_to_window(game->connection, game->window,
			game->enemy_img.img_ptr, px, py);
}

static void	draw_tile(t_solong *game, char cell, t_position pos)
{
	int			px;
	int			py;

	px = pos.x * game->tile;
	py = pos.y * game->tile;
	mlx_put_image_to_window(game->connection, game->window,
		game->floor.img_ptr, px, py);
	if (cell == '1')
		mlx_put_image_to_window(game->connection, game->window,
			game->wall.img_ptr, px, py);
	if (cell == 'P' || (game->player_pos.x == pos.x
			&& game->player_pos.y == pos.y))
		mlx_put_image_to_window(game->connection, game->window,
			game->player.img_ptr, px, py);
	if (cell == 'E')
		mlx_put_image_to_window(game->connection, game->window,
			game->door.img_ptr, px, py);
	draw_tile_aux(game, cell, px, py);
}

static void	print_info(t_solong *game)
{
	char	*submessage;
	char	*message;
	char	*total_c;
	char	*subsupermess;
	char	*supermess;

	submessage = ft_itoa(game->c_moves);
	message = ft_strjoin("Moves: ", submessage);
	mlx_string_put(game->connection, game->window, 84, 86,
		0x000000, message);
	free(submessage);
	free(message);
	total_c = ft_itoa(game->c_total_coll);
	submessage = ft_itoa(game->c_collected);
	message = ft_strjoin("Coins Collected: ", submessage);
	subsupermess = ft_strjoin(message, "/");
	supermess = ft_strjoin(subsupermess, total_c);
	mlx_string_put(game->connection, game->window, 84, 106,
		0x000000, supermess);
	free(total_c);
	free(submessage);
	free(message);
	free(subsupermess);
	free(supermess);
}

void	render_map(t_solong *game)
{
	int			y;
	int			x;
	t_position	pos;

	y = 0;
	while (y < game->m_height)
	{
		x = 0;
		pos.y = y;
		while (x < game->m_width)
		{
			pos.x = x;
			draw_tile(game, game->map[y][x], pos);
			x++;
		}
		y++;
	}
	print_info(game);
}
#endif