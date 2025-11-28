/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:28:12 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/28 17:07:17 by masenjo          ###   ########.fr       */
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
	game->player.img_ptr = mlx_xpm_file_to_image(game->connection, "img/p.xpm",
			&game->player.width, &game->player.height);
	if (!game->player.img_ptr)
		return (destroy_images(game), 0);
	game->door.img_ptr = mlx_xpm_file_to_image(game->connection, "img/e.xpm",
			&game->door.width, &game->door.height);
	if (!game->door.img_ptr)
		return (destroy_images(game), 0);
	if (!load_frames(game, &game->coin_anim, "img/c_"))
	{
		game->coin.img_ptr = mlx_xpm_file_to_image(game->connection, "img/c.xpm",
				&game->coin.width, &game->coin.height);
		if (!game->coin.img_ptr)
			return (destroy_images(game), 0);
	}
	ft_printf("coin_anim.count=%d\n", game->coin_anim.count);
	for (int i = 0; i < game->coin_anim.count; ++i)
    	ft_printf("frame[%d]=%p\n", i, game->coin_anim.frames[i].img_ptr);
	return (1);
}
