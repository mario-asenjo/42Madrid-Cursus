/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:29:14 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/23 20:39:15 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void    draw_tile(t_solong *game, char cell, t_position pos)
{
    int px;
    int py;

    px = pos.x * game->tile;
    py = pos.y * game->tile;
    mlx_put_image_to_window(game->connection, game->window, game->floor.img_ptr, px, py);
    if (cell == '1')
        mlx_put_image_to_window(game->connection, game->window, game->wall.img_ptr, px, py);
    if (cell == 'C')
        mlx_put_image_to_window(game->connection, game->window, game->coin.img_ptr, px, py);
    if (cell == 'P' || (game->player_pos.x == pos.x && game->player_pos.y == pos.y))
        mlx_put_image_to_window(game->connection, game->window, game->player.img_ptr, px, py);
    if (cell == 'E')
        mlx_put_image_to_window(game->connection, game->window, game->door.img_ptr, px, py);
}

void    render_rev(t_solong *game)
{
    int x;
    int y;
    t_position pos;

    y = game->m_height - 1;
    while (y >= 0)
    {
        x = game->m_width - 1;
        pos.y = y;
        while (x >= 0)
        {
            pos.x = x;
            draw_tile(game, game->map[y][x], pos);
            x--;
        }
        y--;
    }
}

void    render_map(t_solong *game)
{
    int y;
    int x;
    t_position pos;

    if (game->player_pos.y > game->exit_pos.y)
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
    else
        render_rev(game);
}