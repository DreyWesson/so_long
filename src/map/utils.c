/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 06:25:55 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/22 20:08:27 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	valid_move(t_nodes **queue)
{
	if (((*queue)->cell->val != SPACE && (*queue)->cell->val != BLOCK))
		return (1);
	return (0);
}

int	validate_paths(t_cell **grid, t_nodes **queue)
{
	int	memo;

	handle_adjacency(grid, queue);
	memo = valid_move(queue);
	del_node(queue);
	if (!*queue)
		return (memo);
	return (validate_paths(grid, queue) + memo);
}
