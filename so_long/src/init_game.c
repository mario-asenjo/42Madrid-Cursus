/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:31:09 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/06 11:14:56 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_image_vals(t_sl_img *img)
{
	img->addr = NULL;
	img->img_ptr = NULL;
	img->width = 0;
	img->height = 0;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
}

static void	init_game_image_vals(t_solong *game)
{
	init_image_vals(&game->wall);
	init_image_vals(&game->floor);
	init_image_vals(&game->player);
	init_image_vals(&game->coin);
	init_image_vals(&game->door);
}

static void	init_game_flags(t_solong *game)
{
	game->c_collected = 0;
	game->c_moves = 0;
	#ifdef BONUS
	game->clock_tick = 0;
	game->enemy_count = 0;
	#endif BONUS
	game->game_finished = 0;
	init_game_image_vals(game);
}

int	init_game(t_solong *game, int width, int height, char *title)
{
	game->connection = mlx_init();
	if (!game->connection)
		return (KO);
	game->tile = 64;
	game->w_width = width * game->tile;
	game->w_height = height * game->tile;
	game->window = mlx_new_window(game->connection,
			game->w_width, game->w_height, title);
	if (!game->window)
		return (destroy_game(game), KO);
	init_game_flags(game);
	return (OK);
}
