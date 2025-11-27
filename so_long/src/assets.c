/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:28:12 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/23 14:42:20 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	assets_load(t_solong *game)
{
	game->wall.img_ptr = mlx_xpm_file_to_image(game->connection, "img/1.xpm",
			&game->wall.width, &game->wall.height);
	if (!game->wall.img_ptr)
		return (destroy_images(game), 0);
	game->floor.img_ptr = mlx_xpm_file_to_image(game->connection, "img/0.xpm",
			&game->floor.width, &game->floor.height);
	if (!game->floor.img_ptr)
		return (destroy_images(game), 0);
	game->coin.img_ptr = mlx_xpm_file_to_image(game->connection, "img/c.xpm",
			&game->coin.width, &game->coin.height);
	if (!game->coin.img_ptr)
		return (destroy_images(game), 0);
	game->player.img_ptr = mlx_xpm_file_to_image(game->connection, "img/p.xpm",
			&game->player.width, &game->player.height);
	if (!game->player.img_ptr)
		return (destroy_images(game), 0);
	game->door.img_ptr = mlx_xpm_file_to_image(game->connection, "img/e.xpm",
			&game->door.width, &game->door.height);
	if (!game->door.img_ptr)
		return (destroy_images(game), 0);
	return (1);
}
