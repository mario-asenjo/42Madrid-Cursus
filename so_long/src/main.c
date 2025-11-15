/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:16:15 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/14 20:11:47 by masenjo          ###   ########.fr       */
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
	ft_printf("Mapa validado.\n");
	if (!init_game(&game, 300, 300, "SoLong - By masenjo - 42Madrid"))
		return (perror("No pudo inicializarse solong_t -> main()."), 1);
	register_hooks(&game);
	ft_printf("%s\n", argv[1]);
	mlx_loop(game.connection);
	return (0);
}
