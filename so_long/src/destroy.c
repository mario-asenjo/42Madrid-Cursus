/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:55:03 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/23 13:58:59 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_images(t_solong *game)
{
	if (game->coin.img_ptr)
	{
		mlx_destroy_image(game->connection, game->coin.img_ptr);
		game->coin.img_ptr = NULL;
	}
	if (game->player.img_ptr)
	{
		mlx_destroy_image(game->connection, game->player.img_ptr);
		game->player.img_ptr = NULL;
	}
	if (game->wall.img_ptr)
	{
		mlx_destroy_image(game->connection, game->wall.img_ptr);
		game->wall.img_ptr = NULL;
	}
	if (game->door.img_ptr)
	{
		mlx_destroy_image(game->connection, game->door.img_ptr);
		game->door.img_ptr = NULL;
	}
	if (game->floor.img_ptr)
	{
		mlx_destroy_image(game->connection, game->floor.img_ptr);
		game->floor.img_ptr = NULL;
	}
}

static void destroy_window(t_solong *game)
{
	if (game->window)
		mlx_destroy_window(game->connection, game->window);
}

void	destroy_game(t_solong *game)
{
	destroy_images(game);
	destroy_window(game);
	game->window = NULL;
	free(game->connection);
	game->connection = NULL;
	map_free(game);
}
