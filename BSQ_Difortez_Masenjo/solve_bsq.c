/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:40:31 by difortez          #+#    #+#             */
/*   Updated: 2025/07/30 18:22:40 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**assign_values(char **map, int **matrix, t_legend *legend)
{
	int	i;
	int	j;

	i = 0;
	while (i < legend->size)
	{
		j = 0;
		while (j < legend->cols)
		{
			if (map[i][j] == legend->obstacle_c)
				matrix[i][j] = 0;
			else if (map[i][j] == legend->empty_c && (i == 0 || j == 0))
				matrix[i][j] = 1;
			else
				matrix[i][j] = -1;
			j++;
		}
		i++;
	}
	return (matrix);
}

int	**init_matrix(char **map, t_legend *legend)
{
	int	**matrix;
	int	i;

	matrix = (int **)malloc(sizeof(int *) * legend->size);
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < legend->size)
	{
		matrix[i] = (int *)malloc(sizeof(int) * legend->cols);
		if (!matrix[i])
		{
			free_matrix(matrix, i);
			return (NULL);
		}
		i++;
	}
	matrix = assign_values(map, matrix, legend);
	return (matrix);
}

int	find_bsq(char **map, int **map_matrix, t_legend *legend)
{
	int	i;
	int	j;
	int	max_square[3];

	max_square[0] = 0;
	max_square[1] = 0;
	max_square[2] = 0;
	i = -1;
	while (++i < legend->size)
	{
		j = -1;
		while (++j < legend->cols)
		{
			if (map_matrix[i][j] == -1)
				map_matrix[i][j] = ft_min(map_matrix, i, j) + 1;
			if (max_square[0] < map_matrix[i][j])
			{
				max_square[0] = map_matrix[i][j];
				max_square[1] = i;
				max_square[2] = j;
			}
		}
	}
	print_bsq(map, max_square, legend);
	return (1);
}

void	print_bsq(char **map, int *max_square, t_legend *legend)
{
	int	i;
	int	j;
	int	start_row;
	int	start_col;

	start_row = max_square[1] - max_square[0] + 1;
	start_col = max_square[2] - max_square[0] + 1;
	i = 0;
	while (i < legend->size)
	{
		j = 0;
		while (j < legend->cols)
		{
			if ((i >= start_row && i <= max_square[1])
				&& (j >= start_col && j <= max_square[2]))
				write(1, &legend->solver_c, 1);
			else
				write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	solve_bsq(char **map, t_legend *legend)
{
	int		**map_matrix;

	map_matrix = init_matrix(map, legend);
	if (!map_matrix)
	{
		free_map(map, legend->size);
		ft_errors("map error\n");
	}
	if (!find_bsq(map, map_matrix, legend))
	{
		free_map(map, legend->size);
		free_matrix(map_matrix, legend->size);
		ft_errors("map error\n");
	}
	free_map(map, legend->size);
	free_matrix(map_matrix, legend->size);
}
