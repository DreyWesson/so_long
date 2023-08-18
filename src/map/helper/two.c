/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 06:28:34 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/18 14:01:16 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

t_cell	**create_grid(char **map, t_details *details)
{
	int		x;
	int		y;
	t_cell	**grid;

	y = 0;
	grid = (t_cell **)ft_calloc(sizeof(t_cell *), details->row_nbr);
	while (y < details->row_nbr)
	{
		x = 0;
		grid[y] = (t_cell *)ft_calloc(sizeof(t_cell), details->col_nbr);
		while (x < details->col_nbr)
		{
			grid[y][x] = create_cell(map[y][x], x, y);
			x++;
		}
		y++;
	}
	return (grid);
}

void	direction_math(t_cell **grid, t_nodes **queue, int y, int x)
{
	if (grid[y][x].status == SPACE && grid[y][x].val != WALL)
	{
		add_head_node(queue, create_node(&grid[y][x]));
		grid[y][x].status = WAITING;
	}
}

void	handle_directions(t_cell **grid, t_nodes **queue)
{
	int	x;
	int	y;

	x = (*queue)->cell->x_axis;
	y = (*queue)->cell->y_axis;
	direction_math(grid, queue, y - 1, x);
	direction_math(grid, queue, y + 1, x);
	direction_math(grid, queue, y, x - 1);
	direction_math(grid, queue, y, x + 1);
	(*queue)->cell->status = VISITED;
}
