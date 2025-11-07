/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:08:50 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/06 20:20:55 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include "ft_printf_bonus.h"
# include "libft.h"
# include "mlx.h"

typedef struct s_sl_img
{
	void	*img_ptr;
	int		width;
	int		height;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_sl_img;


typedef struct s_solong
{
	void		*connection;
	void		*window;
	int			w_width;
	int			w_height;
	int			tile;
	char		**map;
	int			m_width;
	int			m_height;
	int			c_moves;
	int			c_collected;
	int			c_total_coll;
	/*
		SI QUIERO CORRER PONER AQUÍ FLAGSITA
	*/
	t_sl_img	wall;
	t_sl_img	floor;
	t_sl_img	player;
	t_sl_img	coin;
	t_sl_img	door;
}				t_solong;

/*
** Initialize so_long struct / game
** Recieves a struct to initialize, if cannot do it
** returns error code 0 -> KO.
*/
int		init_game(t_solong *game_token, int width, int height, char *title);

/*
** Mimic mlx_pixel_put but many times faster
*/
void    my_mlx_pixel_put(t_sl_img data, int x, int y, int color);

#endif