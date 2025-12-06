/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:16:15 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/06 09:46:59 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_solong	game;

	if (argc != 2)
		return (write(2, "Error.\n", 7), 1);
	if (!map_check_extension(argv[1]))
		return (write(2, "Error.\n", 7), 1);
	if (!map_load(argv[1], &game))
		return (write(2, "Error.\n", 7), map_free(&game), 1);
	if (!find_path_to_exit_with_all_c(&game))
		return (write(2, "Error.\n", 7), map_free(&game), 1);
	if (!init_game(&game, game.m_width, game.m_height,
			"SoLong - By masenjo - 42Madrid"))
		return (write(2, "Error.\n", 7), map_free(&game), 1);
	if (!assets_load(&game))
		return (write(2, "Error.\n", 7), map_free(&game),
			destroy_game(&game), 1);
	render_map(&game);
	register_hooks(&game);
	mlx_loop(game.connection);
	return (0);
}
