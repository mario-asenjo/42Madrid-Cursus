/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:42:06 by difortez          #+#    #+#             */
/*   Updated: 2025/07/30 18:22:22 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	valid_legend(t_legend *legend)
{
	if (legend->solver_c == legend->empty_c
		|| legend->empty_c == legend->obstacle_c
		|| legend->solver_c == legend->obstacle_c)
		return (0);
	if (!(legend->empty_c >= 32 && legend->empty_c <= 126)
		|| !(legend->obstacle_c >= 32 && legend->obstacle_c <= 126)
		|| !(legend->solver_c >= 32 && legend->solver_c <= 126))
		return (0);
	return (1);
}

int	check_columns(char **map, int len)
{
	int	i;
	int	j;
	int	cont;

	i = 0;
	while (map[i])
	{
		j = 0;
		cont = 0;
		while (map[i][j])
		{
			j++;
			cont++;
		}
		if (cont != len)
			return (0);
		i++;
	}
	return (1);
}

int	parse_data(char **map, t_legend *info)
{
	int	r;
	int	c;

	r = 0;
	while (map[r])
	{
		c = 0;
		while (map[r][c])
		{
			if (map[r][c] != info->empty_c && map[r][c] != info->obstacle_c)
				return (0);
			c++;
		}
		r++;
	}
	return (1);
}

int	check_line_count(char *input_data, int size)
{
	int	i;
	int	lines;
	int	first_line;

	i = 0;
	lines = 0;
	first_line = 1;
	while (input_data[i])
	{
		if (input_data[i] == '\n' || input_data[i] == '\0')
		{
			if (first_line)
				first_line = 0;
			else
				lines++;
		}
		i++;
	}
	if (lines != size)
		return (0);
	return (1);
}
