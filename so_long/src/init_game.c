/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:31:09 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/06 21:35:31 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int init_game(t_solong *game_token, int width, int height, char *title)
{
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
