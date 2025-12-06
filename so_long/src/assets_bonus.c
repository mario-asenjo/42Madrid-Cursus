/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:28:12 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/06 13:07:39 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "../include/so_long.h"

static int	load_individual(t_solong *game)
{
	game->wall.img_ptr = mlx_xpm_file_to_image(game->connection,
			"textures/1.xpm", &game->wall.width, &game->wall.height);
	if (!game->wall.img_ptr)
		return (destroy_images(game), 0);
	game->floor.img_ptr = mlx_xpm_file_to_image(game->connection,
			"textures/0.xpm", &game->floor.width, &game->floor.height);
	if (!game->floor.img_ptr)
		return (destroy_images(game), 0);
	game->player.img_ptr = mlx_xpm_file_to_image(game->connection,
			"textures/p.xpm", &game->player.width, &game->player.height);
	if (!game->player.img_ptr)
		return (destroy_images(game), 0);
	game->door.img_ptr = mlx_xpm_file_to_image(game->connection,
			"textures/e.xpm", &game->door.width, &game->door.height);
	if (!game->door.img_ptr)
		return (destroy_images(game), 0);
	game->enemy_img.img_ptr = mlx_xpm_file_to_image(game->connection,
			"textures/x.xpm", &game->enemy_img.width, &game->enemy_img.height);
	if (!game->enemy_img.img_ptr)
		return (destroy_images(game), 0);
	return (1);
}

int	assets_load(t_solong *game)
{
	if (!load_individual(game))
		return (0);
	if (!load_frames(game, &game->coin_anim, "textures/c_"))
	{
		game->coin.img_ptr = mlx_xpm_file_to_image(game->connection,
				"textures/c.xpm", &game->coin.width, &game->coin.height);
		if (!game->coin.img_ptr)
			return (destroy_images(game), 0);
	}
	return (1);
}
#endif