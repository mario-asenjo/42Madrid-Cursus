/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:16:15 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/06 20:27:41 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (perror("Solo se acepta como primer argumento un mapa. -> main().\n"), 1);
	
	/*
		LOGICA DE PARSEO DE MAPA
		DE LA CUAL SACAMOS EL WIDTH Y HEIGHT? O ESO NO DEPENDE DEL MAPA?
	*/

	t_solong game;
	t_sl_img img;

	if (!init_game(&game, 1920, 1080, "Tauste es anormal"))
		return (perror("No pudo inicializarse solong_t -> main()."), 1);
	ft_printf("Todo ha ido OK");
	img.img_ptr = mlx_new_image(game.connection, game.w_width, game.w_height);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(game.connection, game.window, img.img_ptr, 0, 0);
	mlx_loop(game.connection);
	
	return (0);
}
