/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:20:13 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/14 17:40:22 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mouse.h"

int is_left_click(int m)
{
    if (m == M_LEFT_C_LNX)
        return (1);
    return (0);
}

int is_right_click(int m)
{
    if (m == M_RIGHT_C_LNX)
        return (1);
    return (0);
}

int is_mid_click(int m)
{
    if (m == M_SCROLL_C_LNX)
        return (1);
    return (0);
}

int is_scroll_up(int m)
{
    if (m == M_SCROLL_UP_LNX)
        return (1);
    return (0);
}

int is_scroll_dw(int m)
{
    if (m == M_SCROLL_DW_LNX)
        return (1);
    return (0);
}
