/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:37:41 by root              #+#    #+#             */
/*   Updated: 2025/12/06 13:50:17 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	op_rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	op_rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	op_rev_rotate(a);
	op_rev_rotate(b);
	write(1, "rrr\n", 4);
}
