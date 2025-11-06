/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:08:50 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/06 21:28:38 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include "ft_printf_bonus.h"
# include "libft.h"

typedef struct s_sl_img
{
	void	*img_ptr;
	int		width;
	int		height;
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

#endif