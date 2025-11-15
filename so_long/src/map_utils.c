/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 20:04:45 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/15 20:54:17 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_check_extension(char *filename)
{
	if (ft_strncmp(".ber", &filename[ft_strlen(filename) - 4], 4) == 0)
		return (1);
	return (0);
}

void	map_free(t_solong *game)
{
	int	line;

	line = 0;
	while (game->m_height > line)
	{
		if (game->map[line])
			free(game->map[line]);
		line++;
	}
	free(game->map);
}
