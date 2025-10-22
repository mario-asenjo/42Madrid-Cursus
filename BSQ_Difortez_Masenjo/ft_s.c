/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_utils_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:29:13 by masenjo           #+#    #+#             */
/*   Updated: 2025/07/29 18:23:33 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_errors(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
	exit(1);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	ret;

	sign = 1;
	ret = 0;
	while (*str == '0' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		ret = ret * 10 + (*str++ - '0');
	return (ret * sign);
}

int	ft_min(int **matrix, int i, int j)
{
	int	min;

	min = matrix[i - 1][j];
	if (matrix[i][j - 1] < min)
		min = matrix[i][j - 1];
	if (matrix[i - 1][j - 1] < min)
		min = matrix[i - 1][j - 1];
	return (min);
}

void	free_matrix(int **matrix, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_map(char **matrix, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
