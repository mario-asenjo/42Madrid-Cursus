/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:05:59 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/28 20:27:28 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	load_frames(t_solong *game, t_animation *a, char *file)
{
	char	*tmp;
	char	*full;
	int		frame;

	a = (t_animation *)(sizeof(t_animation));
	if (!a)
		return (0);
	a->count = 0;
	while (a->count < 8)
	{
		frame = ft_itoa(a->count);
		if (!frame)
			return (anim_unload(game, a), 0);
		tmp = ft_strjoin(file, frame);
		if (!tmp)
			return (free(frame), anim_unload(game, a), 0);
		full = ft_strjoin(file, ".xpm");
		if (!full)
			return (free(frame), free(tmp), anim_unload(game, a), 0);
		a->frames[a->count].img_ptr = mlx_xpm_file_to_image(game->connection, full, &a->frames[a->count].width, &a->frames[a->count].height);
		if (!a->frames[a->count].img_ptr)
			return (free(frame), free(file), free(full), anim_unload(game, a), 0);
		free(frame);
		free(tmp);
		free(full);
		if (a->frames[a->count].width != game->tile || a->frames[a->count].height != game->tile)
			return (anim_unload(game, a), 0);
		a->count++;
	}
	a->cur = 0;
	a->ticks = 0;
	a->ticks_per_frame = 8;
	return (a->count > 0);
}
