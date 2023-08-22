/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 06:25:55 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/22 21:25:01 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	valid_move(t_nodes **queue)
{
	if (((*queue)->cell->val != SPACE && (*queue)->cell->val != BLOCK))
		return (1);
	return (0);
}

int	validate_paths(t_cell **grid, t_nodes **queue, t_details details)
{
	int	memo;

	if (grid[details.pos.y][details.pos.x].val == 'P')
		add_head_node(queue, create_node(&grid[details.pos.y][details.pos.x]));
	handle_adjacency(grid, queue);
	memo = valid_move(queue);
	del_node(queue);
	if (!*queue)
		return (memo);
	details.pos.x = (*queue)->cell->x_axis;
	details.pos.y = (*queue)->cell->y_axis;
	return (validate_paths(grid, queue, details) + memo);
}
