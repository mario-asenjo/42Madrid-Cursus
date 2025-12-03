/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:18:26 by root              #+#    #+#             */
/*   Updated: 2025/12/03 12:20:54 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *a)
{
	int first;
	int second;
	int third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->bottom->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);

		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min_pos;
	int	dist;

	min_pos = stack_get_min_position(a);
	if (min_pos <= a->size / 2)
	{
		while (min_pos-- > 0)
			ra(a);
	}
	else
	{
		dist = a->size - min_pos;
		while (dist-- > 0)
			rra(a);
	}
	pb(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		push_min_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
