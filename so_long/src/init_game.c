/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:31:09 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/19 13:30:38 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void init_image_vals(t_sl_img *img) {
	img->addr = NULL;
	img->img_ptr = NULL;
	img->width = 0;
	img->height = 0;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
}

static void init_game_image_vals(t_solong *game) {
	init_image_vals(&game->wall);
	init_image_vals(&game->floor);
	init_image_vals(&game->player);
	init_image_vals(&game->coin);
	init_image_vals(&game->door);
}

static void init_game_flags(t_solong *game) {
	game->c_collected = 0;
	game->c_moves = 0;
	game->player_pos.x = 0;
	game->player_pos.y = 0;
	init_game_image_vals(game);
}

int	init_game(t_solong *game_token, int width, int height, char *title)
{
	game_token->connection = mlx_init();
	if (!game_token->connection)
		return (KO);
	game_token->tile = 64;
	game_token->w_width = width * game_token->tile;
	game_token->w_height = height * game_token->tile;
	game_token->window = mlx_new_window(game_token->connection,
			game_token->w_width, game_token->w_height, title);
	if (!game_token->window)
		return (destroy_game(game_token, 1), KO);
	init_game_flags(game_token);
	return (OK);
}
