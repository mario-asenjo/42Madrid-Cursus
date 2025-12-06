/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:53:58 by root              #+#    #+#             */
/*   Updated: 2025/12/06 09:41:15 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    exit_code(t_stack *a, t_stack *b, int code)
{
    if (a)
        stack_clear(a);
    if (b)
        stack_clear(b);
    if (code == ERROR_ARGS || code == ERROR_PARSING)
        write(2, "Error\n", 6);
    exit(code);
}

