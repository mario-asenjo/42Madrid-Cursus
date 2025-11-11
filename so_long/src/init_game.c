/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:31:09 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/11 19:38:50 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_images(t_solong *game)
{
	ft_memset(game->coin, 0, sizeof(t_sl_img *));
	ft_memset(game->floor, 0, sizeof(t_sl_img *));
	ft_memset(game->door, 0, sizeof(t_sl_img *));
	ft_memset(game->player, 0, sizeof(t_sl_img *));
	ft_memset(game->wall, 0, sizeof(t_sl_img *));
}

int	init_game(t_solong *game_token, int width, int height, char *title)
{
	ft_memset(game_token, 0, sizeof(t_solong));
	init_images(game_token);
	game_token->connection = mlx_init();
	if (!game_token->connection)
		return (KO);
	game_token->w_width = width;
	game_token->w_height = height;
	game_token->window = mlx_new_window(game_token->connection,
			game_token->w_width, game_token->w_height, title);
	if (!game_token->window)
		return (KO);
	return (OK);
}
