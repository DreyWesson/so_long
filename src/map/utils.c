/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 06:25:55 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/18 06:40:31 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	bfs(t_cell **grid, t_nodes **queue, t_details *details)
{
	t_details	tmp;
	int			memo;

	details->pos.x = (*queue)->cell->x_axis;
	details->pos.y = (*queue)->cell->y_axis;
	handle_directions(grid, queue, details);
	(*queue)->cell->status = VISITED;
	memo = 0;
	if (((*queue)->cell->val != SPACE && (*queue)->cell->val != WALL))
		memo = 1;
	del_node(queue);
	if (!*queue && memo == 1)
		return (1);
	if (!*queue)
		return (0);
	tmp = set_tmp(queue, details);
	// print_node(*queue, details->col_nbr);
	// printf("\n");
	return (bfs(grid, queue, &tmp) + memo);
}
