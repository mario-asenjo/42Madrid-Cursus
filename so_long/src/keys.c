/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:41:49 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/11 18:42:40 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/keys.h"

int	is_esc(int k)
{
	return (k == K_ESC_MAC || k == K_ESC_LNX);
}

int	is_left(int k)
{
	return (k == K_A_MAC || k == K_LEFT_MAC || k == K_A_LNX || k == K_LEFT_LNX);
}

int	is_right(int k)
{
	return (k == K_D_MAC || k == K_RIGHT_MAC
		|| k == K_D_LNX || k == K_RIGHT_LNX);
}

int	is_up(int k)
{
	return (k == K_W_MAC || k == K_UP_MAC || k == K_W_LNX || k == K_UP_LNX);
}

int	is_down(int k)
{
	return (k == K_S_MAC || k == K_DOWN_MAC || k == K_S_LNX || k == K_DOWN_LNX);
}
