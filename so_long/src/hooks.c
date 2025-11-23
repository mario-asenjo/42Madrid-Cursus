/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:16:21 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/14 19:42:45 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/keys.h"
#include "../include/mouse.h"

int	on_close(t_solong *game)
{
	ft_printf("Procediendo a cerrar el juego.\n");
	destroy_game(game, 0);
	return (0);
}

int	on_key(int keycode, t_solong *game)
{
	if (is_esc(keycode))
		on_close(game);
	else if (is_down(keycode))
	{
		game->c_moves++;
		ft_printf("Vas hacia abajo Count: %d\n", game->c_moves);
	}
	else if (is_up(keycode))
	{
		game->c_moves++;
		ft_printf("Vas hacia arrba Count: %d\n", game->c_moves);
	}
	else if (is_left(keycode))
	{
		game->c_moves++;
		ft_printf("Vas hacia la izquierda Count: %d\n", game->c_moves);
	}
	else if (is_right(keycode))
	{
		game->c_moves++;
		ft_printf("Vas hacia la derecha Count: %d\n", game->c_moves);
	}
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