/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:08:50 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/06 11:30:31 by masenjo          ###   ########.fr       */
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
# define MAX_ENEMIES 24

typedef struct s_position {
	int	x;
	int	y;
}		t_position;

typedef struct s_map_vals {
	int	line;
	int	col;
	int	e_flag;
	int	p_flag;
}		t_map_vals;

typedef struct s_sl_img {
	void	*img_ptr;
	int		width;
	int		height;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_sl_img;

/* --- Base State (mandatory part) --- */
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
	int			game_finished;

	t_position	player_pos;
	t_position	exit_pos;

	t_sl_img	wall;
	t_sl_img	floor;
	t_sl_img	player;
	t_sl_img	door;
	t_sl_img	coin;

	/* --------- BONUS PART --------- */
	#ifdef BONUS
	# define ANIM_COIN_FRAMES 8
	# define COIN_TICKS_PER_FRAME 300
	# define ENEMY_STEP_TICKS 2500

	typedef struct s_animation {
		t_sl_img	frames[ANIM_COIN_FRAMES];
		int			count;
		int			cur;
		int			ticks;
		int			ticks_per_frame;
	} t_animation;

	typedef struct s_enemy {
		t_position	pos;
		t_position	origin;
		int			dirx;
	} t_enemy;

	typedef struct s_routine_info {
		t_position	old_pos;
		t_position	next;
		int			nextx;
		int			move_ok;
	} t_routine_info;

	t_sl_img	enemy_img;
	t_animation	coin_anim;
	int			clock_tick;

	t_enemy		enemies[MAX_ENEMIES];
	int			enemy_count;
	#endif
	/* ------------------------- */

}				t_solong;

/* common prototypes (mandatory) */
char	*get_next_line(int fd);
int		ft_iscinstr(const char *str, char c);

int		init_game(t_solong *game, int width, int height, char *title);
void	destroy_game(t_solong *game);
int		on_close(t_solong *game);
void	end_game(t_solong *game, int exit_code);
void	register_hooks(t_solong *game);

char	**map_load(char *filename, t_solong *game);
char	**map_copy(char *filename, int line_count, t_solong *game);
int		map_validate(t_solong *game);
int		map_count_lines(char *filename);
int		map_validate_aux(const t_solong *g);
int		line_check(char c, t_solong *game, t_map_vals *map_vals);
void	map_free(t_solong *game);
int		map_check_extension(char *filename);
int		find_path_to_exit_with_all_c(t_solong *game);

void	my_mlx_pixel_put(t_sl_img *data, int x, int y, int color);
void	destroy_images(t_solong *game);
void	render_map(t_solong *game);
int		assets_load(t_solong *game);

int		is_walkable(t_position pos, t_solong *game);
int		in_bounds(t_position pos, t_solong *game);
int		index_of(t_position p, t_solong *game);

int		try_move_player(t_solong *game, int add_x, int add_y);

/* BONUS prototypes only visible if BONUS=1 */
#ifdef BONUS
int		load_frames(t_solong *game, t_animation *a, const char *prefix);
void	anim_unload(t_solong *game, t_animation *a);
void	enemy_step(t_solong *g);
int     on_loop(void *param);
#endif

#endif