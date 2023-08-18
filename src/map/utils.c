/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 06:25:55 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/18 11:40:15 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int valid_move(t_nodes **queue)
{
	if (((*queue)->cell->val != SPACE && (*queue)->cell->val != WALL))
		return (1);
	return (0);
}

int	bfs(t_cell **grid, t_nodes **queue, t_details *details)
{
	t_details	tmp;
	int			memo;

	details->pos.x = (*queue)->cell->x_axis;
	details->pos.y = (*queue)->cell->y_axis;
	handle_directions(grid, queue, details);
	memo = valid_move(queue);
	del_node(queue);
	if (!*queue)
		return (memo);
	tmp = set_tmp(queue, details);
	return (bfs(grid, queue, &tmp) + memo);
}
