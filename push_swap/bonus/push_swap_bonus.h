/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 07:28:01 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/09 07:09:10 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# define OPS_INIT_ERROR 6
# define STDIN_READ_ERROR 7

# include "../push_swap.h"
# include "gnl/get_next_line_bonus.h"

/**
 * Efectuate operations in list *ops, on both stacks *a and *b
 */
void	efectuate_operations(t_stack *a, t_stack *b, t_list_gnl *ops);
int     read_standard_input(t_list_gnl **ops);
#endif