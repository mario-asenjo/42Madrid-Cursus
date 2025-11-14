/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:14:55 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/14 18:05:42 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# define M_LEFT_C_LNX    1
# define M_SCROLL_C_LNX  2
# define M_RIGHT_C_LNX   3
# define M_SCROLL_UP_LNX 4
# define M_SCROLL_DW_LNX 5

int	is_left_click(int m);
int	is_right_click(int m);
int	is_mid_click(int m);
int	is_scroll_up(int m);
int is_scroll_dw(int m);

#endif