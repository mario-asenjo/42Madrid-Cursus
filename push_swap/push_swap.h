/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:37:18 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/03 12:23:48 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "ft_printf/ft_printf_bonus.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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
 * Abstraction of stack using t_node
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
 * STACK INTIALIZATION AND CLEARING FUNCS
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
/**
 * stack_is_sorted -> Returns 1 if stack is NULL, sized < 2 or 
 * 					  when stack is sorted.
*/
int stack_is_sorted(t_stack *stack);

/**
 * UTILS OF THE STACK (GET LOWEST VALUE'S POSITION, )
 * sort_utils.c
*/

/**
 * stack_get_min_position -> Retrieves position of lowest value node in stack.
*/
int	stack_get_min_position(t_stack *stack);

/**
 * GENERIC OPERATIONS IN STACK
 * stack_basic_ops.c
*/

/**
 * stack_push_top -> adds node on top of stack both sent as 
 * 					 parameters.
*/
void    stack_push_top(t_stack *stack, t_node *node);
/**
 * stack_pop_top -> pops top node of stack sent as parameter.
*/
t_node  *stack_pop_top(t_stack *stack);
/**
 * stack_push_bottom -> adds node to bottom of stack both sent
 * 					    as parameters.
*/
void    stack_push_bottom(t_stack *stack, t_node *node);

/**
 * SWAP GENERIC FUNTIONS ON STACKS
 * stack_swap_generic.c
*/

/**
 * op_swap -> if size >= 2 swaps first two nodes of stack sent
 * 			  as parameter.
*/
void    op_swap(t_stack *stack);
/**
 * op_push -> moves top from "from" to "to" stacks sent as parameters.
*/
void    op_push(t_stack *from, t_stack *to);
/**
 * op_rotate -> pushes the top node to the bottom of the stack sent as
 * 				parameter.
*/
void    op_rotate(t_stack *stack);
/**
 * op_rev_rotate -> pushes the bottom node to the top of the stack sent
 * 					as parameter.
*/
void    op_rev_rotate(t_stack *stack);

/**
 * SWAP OPERATIONS
 * ops_swap.c
*/

/**
 * sa -> calls op_swap on a sent as parameter, then prints 'sa'
*/
void    sa(t_stack *a);
/**
 * sb -> calls op_swap on b sent as parameter, then prints 'sb'
*/
void    sb(t_stack *b);
/**
 * ss -> calls op_swap on a and b both sent as parameters, then prints 'ss'
*/
void    ss(t_stack *a, t_stack *b);

/**
 * PUSH OPERATIONS
 * ops_push.c
*/

/**
 * pa -> calls op_push from b to a both sent as parameters, then prints 'pa'
*/
void    pa(t_stack *a, t_stack *b);
/**
 * pb -> calls op_push from a to b both sent as parameters, then prints 'pb'
*/
void    pb(t_stack *a, t_stack *b);

/**
 * ROTATE OPERATIONS
 * ops_rotate.c
*/

/**
 * ra -> calls op_rotate on a sent as parameter, then prints 'ra'
*/
void    ra(t_stack *a);
/**
 * rb -> calls op_rotate on b sent as parameter, then prints 'rb'
*/
void    rb(t_stack *b);
/**
 * rr -> calls op_rotate on a and b both sent as parameters, then prints 'rr'
*/
void    rr(t_stack *a, t_stack *b);

/**
 * REVERSE ROTATE OPERATIONS
 * ops_rev_rotate.c
*/

/**
 * rra -> calls op_rev_rotate on a sent as parameter, then prints 'rra'
*/
void    rra(t_stack *a);
/**
 * rrb -> calls op_rev_rotate on b sent as parameter, then prints 'rrb'
*/
void    rrb(t_stack *b);
/**
 * rrr -> calls op_rev_rotate on a and b both sent as parameters,
 * 		  then prints 'rrr'
*/
void    rrr(t_stack *a, t_stack *b);

/**
 * PARSING ARGUMENTS AND CREATING STACK
 * parse_args.c
*/

/**
 * parse_args-> parses numbers in argv to a stack recieved as parameter
*/
int		parse_args(int argc, char **argv, t_stack *a);

/**
 * EXIT HANDLERS
 * exit.c
*/

/**
 * exit_code -> For closing stacks sent as parameters and exiting with
 * 				exit code.
*/
void    exit_code(t_stack *a, t_stack *b, int code);

/**
 * SORTING ALGORITHMS
 * sort_small.c / sort_big.c
*/

/**
 * sort_five -> Sorts stack a using stacks a and b, when a->size <= 5.
*/
void	sort_five(t_stack *a, t_stack *b);
/**
 * sort_big -> Sorts stack a using stacks a and b when a->size > 5.
*/
void	sort_big(t_stack *a, t_stack *b);

#endif