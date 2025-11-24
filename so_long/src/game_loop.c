/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 19:29:46 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/23 20:42:03 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int try_move_player(t_solong *game, int add_x, int add_y)
{
    t_position next;

    next.x = game->player_pos.x + add_x;
    next.y = game->player_pos.y + add_y;
    if (!in_bounds(next, game))
        return (0);
    if (!is_walkable(next, game))
        return (0);
    if (game->map[next.y][next.x] == 'E')
    {
        if (game->c_collected == game->c_total_coll)
        {
            ft_printf("You won!! Congrats!!\n");
            end_game(game, 0);
        }
    }
    if (game->map[next.y][next.x] == 'C')
    {
        game->c_collected++;
        game->map[next.y][next.x] = '0';
    }
    if (game->map[game->player_pos.y][game->player_pos.x] != 'E')
        game->map[game->player_pos.y][game->player_pos.x] = '0';
    game->player_pos = next;
    game->c_moves++;
    mlx_string_put(game->connection, game->window, 1 * game->tile, 1 * game->tile, 5, "Moves: ");
    return (1);
}
