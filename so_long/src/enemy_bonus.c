/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:25:06 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/06 13:07:28 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "../include/so_long.h"

static int	can_step_to(t_solong *game, t_position next, int allow_player_hit)
{
	int	ok;

	ok = 1;
	if (ok && !in_bounds(next, game))
		ok = 0;
	if (ok && game->map[next.y][next.x] == '1')
		ok = 0;
	if (ok && game->map[next.y][next.x] != '0'
		&& !(allow_player_hit && next.x == game->player_pos.x
		&& next.y == game->player_pos.y))
		ok = 0;
	return (ok);
}

static void	check_collision(t_solong *game, t_enemy *enemy,
		t_routine_info *rinfo)
{
	if (rinfo->next.x == game->player_pos.x
		&& rinfo->next.y == game->player_pos.y)
	{
		ft_printf("You have been eaten!!! GAME OVER :(( .\n");
		end_game(game, 1);
	}
	else
	{
		if (game->map[rinfo->old_pos.y][rinfo->old_pos.x] == 'X')
			game->map[rinfo->old_pos.y][rinfo->old_pos.x] = '0';
		game->map[rinfo->next.y][rinfo->next.x] = 'X';
		enemy->pos = rinfo->next;
	}
}

static void	end_routine(t_solong *game, t_enemy *enemy,
		t_routine_info *rinfo, int *i)
{
	if (!rinfo->move_ok)
	{
		enemy->dirx = -enemy->dirx;
		rinfo->next.x = rinfo->old_pos.x + enemy->dirx;
		rinfo->next.y = rinfo->old_pos.y;
		rinfo->move_ok = can_step_to(game, rinfo->next, 1);
	}
	if (rinfo->move_ok)
	{
		check_collision(game, enemy, rinfo);
	}
	(*i)++;
}

static void	start_routine(t_solong *game, int *i)
{
	t_enemy			*enemy;
	t_routine_info	rinfo;

	enemy = &game->enemies[*i];
	rinfo.old_pos = enemy->pos;
	rinfo.nextx = rinfo.old_pos.x + enemy->dirx;
	if (rinfo.nextx > enemy->origin.x + 1 || rinfo.nextx < enemy->origin.x - 1)
	{
		enemy->dirx = -enemy->dirx;
		rinfo.nextx = rinfo.old_pos.x + enemy->dirx;
	}
	rinfo.next.x = rinfo.nextx;
	rinfo.next.y = rinfo.old_pos.y;
	rinfo.move_ok = can_step_to(game, rinfo.next, 1);
	end_routine(game, enemy, &rinfo, i);
}

void	enemy_step(t_solong *game)
{
	int	i;

	i = 0;
	while (i < game->enemy_count)
		start_routine(game, &i);
}

#endif	