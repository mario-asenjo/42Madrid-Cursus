/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:30:09 by root              #+#    #+#             */
/*   Updated: 2025/12/02 16:35:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_stack *a)
{
    op_rotate(a);
    write(1, "ra\n", 3);
}

void    rb(t_stack *b)
{
    op_rotate(b);
    write(1, "rb\n", 3);
}

void    rr(t_stack *a, t_stack *b)
{
    op_rotate(a);
    op_rotate(b);
    write(1, "rr\n", 3);
}
