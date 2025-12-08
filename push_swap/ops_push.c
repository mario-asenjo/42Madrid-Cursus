/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:26:34 by root              #+#    #+#             */
/*   Updated: 2025/12/08 07:15:23 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	op_push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	op_push(a, b);
	write(1, "pb\n", 3);
}
