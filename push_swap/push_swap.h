/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:37:18 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/02 20:55:02 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdlib.h>

/**
 * Each node from the stack
 * value -> original value.
 * index -> position in ordered array
 * next and prev makes this a doubly linked node which helps in rotations.
 */
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

/**
 * Estructura de abstracción de stack
 * top -> hill of stack
 * bottom -> bottom of stack
 * size -> number of elements
 * name -> 'a' or 'b' mostly for debug
 */
typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
	char	name;
}			t_stack;


/**
 * STACK INTIALIZATION AND CLEAR FUNCS
 * stack_init.c
 */

/**
 * new_node -> returns a new node with value sent as parameter.
 */
t_node  *new_node(int value);
 /**
  * stack_init -> initializes stack given as parameter with name
  * 			  given as parameter.
  */
void    stack_init(t_stack *stack, char name);
/**
 * stack_clear -> clears from top, till last node, then sets
 *  			  default values.
 */
void    stack_clear(t_stack *stack);



#endif