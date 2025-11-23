/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:08:50 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/23 14:08:10 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "ft_printf_bonus.h"
# include "libft.h"
# include "mlx.h"

typedef struct s_position
{
	int	x;
	int	y;
}		t_position;

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

	t_position	player_pos;
	t_position	exit_pos;

	t_sl_img	wall;
	t_sl_img	floor;
	t_sl_img	player;
	t_sl_img	coin;
	t_sl_img	door;
}				t_solong;

char	*get_next_line(int fd);

int		init_game(t_solong *game_token, int width, int height, char *title);
void	destroy_game(t_solong *game);
void	register_hooks(t_solong *game);

char	**map_load(char *filename, t_solong *game);
void	map_free(t_solong *game);
int		map_check_extension(char *filename);
int 	find_path_to_exit_with_all_c(t_solong *game);

void    my_mlx_pixel_put(t_sl_img *data, int x, int y, int color);
void	destroy_images(t_solong *game);
void    render_map(t_solong *game);
int 	assets_load(t_solong *game);

#endif
