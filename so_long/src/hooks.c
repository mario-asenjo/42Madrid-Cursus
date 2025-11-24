/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:16:21 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/23 20:51:05 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/keys.h"
#include "../include/mouse.h"

int	on_close(t_solong *game)
{
	ft_printf("Procediendo a cerrar el juego.\n");
	destroy_game(game);
	exit(0);
	return (0);
}

static void next_move(t_solong *game, int x, int y)
{
	char	*submessage;
	char	*message;
	
	if (try_move_player(game, x, y))
	{
		render_map(game);
		submessage = ft_itoa(game->c_moves);
		message = ft_strjoin("Moves: ", submessage);
    	mlx_string_put(game->connection, game->window, 20, 50, 0x6622AF, message);
		free(submessage);
		free(message);
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

int	on_mouse(int button, int x, int y, t_solong *game)
{
	if (is_left_click(button))
		ft_printf("Click izquierdo pulsado en:\nx: %d\ny: %d\n", x, y);
	else if (is_right_click(button))
		ft_printf("Click derecho pulsado en:\nx: %d\ny: %d\n", x, y);
	else if (is_mid_click(button))
		ft_printf("Click de la rueda pulsado en:\nx: %d\ny: %d\n", x, y);
	else if (is_scroll_up(button))
		ft_printf("Scroll hacia arriba hecho en:\nx: %d\ny: %d\n", x, y);
	else if (is_scroll_dw(button))
		ft_printf("Scroll hacia ababjo hecho en:\nx: %d\ny: %d\n", x, y);
	ft_printf("Map Vals: TileSize: %d\n", game->tile);
	return (0);
}

void	register_hooks(t_solong *game)
{
	mlx_key_hook(game->window, on_key, game);
	mlx_mouse_hook(game->window, on_mouse, game);
	mlx_hook(game->window, 17, 0, on_close, game);
}