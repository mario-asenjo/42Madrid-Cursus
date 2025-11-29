/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:25:06 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/28 18:58:12 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int can_step_to(t_solong *g, t_position next, int allow_player_hit)
{
    int ok;

    ok = 1;
    if (ok && !in_bounds(next, g))
        ok = 0;
    if (ok && g->map[next.y][next.x] == '1')
        ok = 0;
    if (ok && g->map[next.y][next.x] != '0'
        && !(allow_player_hit && next.x == g->player_pos.x && next.y == g->player_pos.y))
        ok = 0;
    return ok;
}

static void end_routine(t_solong *g, t_enemy *e,t_routine_info *rinfo, int *i)
{
        if (!rinfo->move_ok)
        {
            e->dirx = -e->dirx;
            rinfo->next.x = rinfo->old_pos.x + e->dirx;
            rinfo->next.y = rinfo->old_pos.y;
            rinfo->move_ok = can_step_to(g, rinfo->next, 1);
        }
        if (rinfo->move_ok)
        {
            int hits_player;

            hits_player = (rinfo->next.x == g->player_pos.x && rinfo->next.y == g->player_pos.y);

            if (hits_player)
            {
                ft_printf("You have been eaten!!! GAME OVER :(( .\n");
                end_game(g, 1);
            }
            else
            {
                if (g->map[rinfo->old_pos.y][rinfo->old_pos.x] == 'X')
                    g->map[rinfo->old_pos.y][rinfo->old_pos.x] = '0';
                g->map[rinfo->next.y][rinfo->next.x] = 'X';
                e->pos = rinfo->next;
            }
        }
        (*i)++;
}

static void start_routine(t_solong *g, int *i)
{
    t_enemy    *e;
    t_routine_info rinfo;

    e = &g->enemies[*i];
    rinfo.old_pos = e->pos;
    rinfo.nextx = rinfo.old_pos.x + e->dirx;
    if (rinfo.nextx > e->origin.x + 1 || rinfo.nextx < e->origin.x - 1)
    {
        e->dirx = -e->dirx;
        rinfo.nextx = rinfo.old_pos.x + e->dirx;
    }
    rinfo.next.x = rinfo.nextx;
    rinfo.next.y = rinfo.old_pos.y;
    rinfo.move_ok = can_step_to(g, rinfo.next, 1);
    end_routine(g, e, &rinfo, i);
}

void enemy_step(t_solong *g)
{
    int i;

    i = 0;
    while (i < g->enemy_count)
        start_routine(g, &i);
}