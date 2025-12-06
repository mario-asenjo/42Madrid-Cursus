/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:05:59 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/06 11:10:28 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
#include "../include/so_long.h"
void	anim_unload(t_solong *game, t_animation *a)
{
	int	i;

	i = 0;
	while (i < a->count)
	{
		if (a->frames[i].img_ptr)
			mlx_destroy_image(game->connection, a->frames[i].img_ptr);
		a->frames[i].img_ptr = NULL;
		i++;
	}
	a->count = 0;
	a->cur = 0;
	a->ticks = 0;
}

static int	load(t_solong *game, t_animation *a, char *file)
{
	char	*full;
	char	*temp;
	char	*frame_str;

	frame_str = ft_itoa(a->count);
	if (!frame_str)
		return (anim_unload(game, a), 0);
	temp = ft_strjoin(file, frame_str);
	if (!temp)
		return (free(frame_str), anim_unload(game, a), 0);
	full = ft_strjoin(temp, ".xpm");
	if (!full)
		return (free(frame_str), anim_unload(game, a), 0);
	a->frames[a->count].img_ptr = mlx_xpm_file_to_image(
			game->connection, full, &a->frames[a->count].width,
			&a->frames[a->count].height);
	if (!a->frames[a->count].img_ptr)
	{
		free(full);
		return (anim_unload(game, a), 0);
	}
	free(frame_str);
	free(temp);
	free(full);
	return (1);
}

int	load_frames(t_solong *game, t_animation *a, char *file)
{
	a->count = 0;
	while (a->count < 8)
	{
		if (!load(game, a, file))
			return (0);
		a->count++;
	}
	a->cur = 0;
	a->ticks = 0;
	a->ticks_per_frame = 300;
	return (a->count > 0);
}
#endif