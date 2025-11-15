/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 20:04:45 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/14 20:08:23 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_check_extension(char *filename)
{
	if (ft_strncmp(".ber", &filename[ft_strlen(filename) - 4], 4) == 0)
		return (1);
	return (0);
}
