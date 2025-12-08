/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:53:24 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/08 07:02:16 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *arr, int i, int j)
{
	int	temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

static void	insertion(int *arr, t_node *curr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (curr)
	{
		arr[i++] = curr->value;
		curr = curr->next;
	}
	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[i])
				swap(arr, i, j);
			j++;
		}
		i++;
	}
}

static void	indexing(int *arr, t_node *curr, int n)
{
	int	i;

	while (curr)
	{
		i = 0;
		while (i < n)
		{
			if (curr->value == arr[i])
			{
				curr->index = i;
				break ;
			}
			i++;
		}
		curr = curr->next;
	}
}

int	index_stack(t_stack *stack)
{
	int		n;
	int		*arr;
	t_node	*curr;

	n = stack->size;
	arr = (int *) malloc(sizeof(int) * n);
	if (!arr)
		return (0);
	curr = stack->top;
	insertion(arr, curr, n);
	curr = stack->top;
	indexing(arr, curr, n);
	free(arr);
	return (1);
}
