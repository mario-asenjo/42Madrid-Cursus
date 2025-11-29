/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:16:21 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/28 18:37:47 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/keys.h"

int	on_close(t_solong *game)
{
	ft_printf("We're closing the game, bye!.\n");
	destroy_game(game);
	exit(0);
	return (0);
}

static void	next_move(t_solong *game, int x, int y)
{
	if (try_move_player(game, x, y))
	{
		enemy_step(game);
		render_map(game);
	}
}

int	on_key(int keycode, t_solong *game)
{
	if (is_esc(keycode))
		on_close(game);
	else if (is_down(keycode))
		next_move(game, 0, 1);
	else if (is_up(keycode))
		next_move(game, 0, -1);
	else if (is_left(keycode))
		next_move(game, -1, 0);
	else if (is_right(keycode))
		next_move(game, 1, 0);
	return (0);
}

static int	on_loop(void *param)
{
	t_solong *game = param;

	game->clock_tick++;
	if (game->coin_anim.count != 0 && game->clock_tick % game->coin_anim.ticks_per_frame == 0)
	{
		game->coin_anim.cur = (game->coin_anim.cur + 1) % game->coin_anim.count;
		render_map(game);
	}
	return (0);
}

void	register_hooks(t_solong *game)
{
	mlx_key_hook(game->window, on_key, game);
	mlx_hook(game->window, 17, 0, on_close, game);
	mlx_loop_hook(game->connection, on_loop, game);
}
