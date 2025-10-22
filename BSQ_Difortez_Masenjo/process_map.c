/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:13:39 by masenjo           #+#    #+#             */
/*   Updated: 2025/07/30 18:19:41 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	process_std_in(void)
{
	char	*input_data;
	int		bytes;

	input_data = (char *)malloc(STD_BUFF_SIZE);
	if (!input_data)
		ft_errors("map error\n");
	bytes = read(0, input_data, STD_BUFF_SIZE - 1);
	if (bytes <= 0)
	{
		free(input_data);
		ft_errors("map error\n");
	}
	input_data[bytes] = '\0';
	process_map(input_data);
	free(input_data);
}

int	fill_map_line(char **map, char *input_data, int *i, int *k)
{
	int	j;
	int	z;

	z = 0;
	j = 0;
	while (input_data[*i + j] && input_data[*i + j] != '\n')
		j++;
	map[*k] = (char *)malloc(j + 1);
	if (!map[*k])
		return (0);
	while (z < j)
	{
		map[*k][z] = input_data[*i + z];
		z++;
	}
	map[*k][j] = '\0';
	*i += j + 1;
	return (1);
}

char	**ft_splitlines(char *input_data, int start, int rows, t_legend *info)
{
	char	**map;
	int		i;
	int		k;

	map = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!map)
		return (NULL);
	map[rows] = NULL;
	i = 0;
	while (start > 0 && input_data[i])
	{
		if (input_data[i++] == '\n')
			start--;
	}
	k = 0;
	while (k < rows)
	{
		if (!fill_map_line(map, input_data, &i, &k))
			ft_errors("map error\n");
		k++;
	}
	if (!parse_data(map, info)
		|| !check_columns(map, count_columns(map[0])))
		ft_errors("map error\n");
	return (map);
}

int	count_columns(char *line)
{
	int	len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	return (len);
}

void	process_map(char *input_data)
{
	t_legend	*info;
	char		header[100];
	char		**map;

	info = init_legend(input_data, header);
	map = ft_splitlines(input_data, 1, info->size, info);
	if (!map)
	{
		free(info);
		ft_errors("map error\n");
	}
	info->cols = count_columns(map[0]);
	if (!check_line_count(input_data, info->size))
		ft_errors("map error\n");
	solve_bsq(map, info);
	free(info);
}
