/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:16:21 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/11 19:14:44 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	register_hooks(t_solong *game)
{
	mlx_key_hook(game->window, on_key, game);
	//mlx_mouse_hook(game->window, on_mouse, game);
	mlx_hook(game->window, 17, 0, on_close, game);
}

int	on_key(int keycode, t_solong *game)
{
	if (is_esc(keycode))
		destroy_game(game, 0);
	else if (is_down(keycode))
		ft_printf("Vas hacia abajo\n");
	else if (is_up(keycode))
		ft_printf("Vas hacia arriba\n");
	else if (is_left(keycode))
		ft_printf("Vas hacia izquierda\n");
	else if (is_right(keycode))
		ft_printf("Vas hacia derecha\n");
	return (1);
}

/* int	on_mouse(int button, int x, int y, t_solong *game)
{
	if ()
} */

int	on_close(t_solong *game)
{
	destroy_game(game, 0);
	return (1);
}
