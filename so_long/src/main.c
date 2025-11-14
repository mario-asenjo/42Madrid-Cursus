/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:16:15 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/11 19:18:17 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_solong	game;

	if (argc != 2)
		return (perror("Solo se acepta como primer argumento un mapa. -> main().\n"), -1);

	/*
		LOGICA DE PARSEO DE MAPA
		DE LA CUAL SACAMOS EL WIDTH Y HEIGHT? O ESO NO DEPENDE DEL MAPA?
	*/

	if (!init_game(&game, 300, 300, "SoLong - By masenjo - 42Madrid"))
		return (perror("No pudo inicializarse solong_t -> main()."), 1);
	register_hooks(&game);
	ft_printf("%s\n", argv[1]);
	mlx_loop(game.connection);
	return (0);
}
