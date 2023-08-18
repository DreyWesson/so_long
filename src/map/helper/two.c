/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 06:28:34 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/18 06:29:52 by doduwole         ###   ########.fr       */
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

void	handle_directions(t_cell **grid, t_nodes **queue, t_details *details)
{
	int x;
	int y;

	x = details->pos.x;
	y = details->pos.y;
	if (grid[y - 1][x].status == SPACE && grid[y - 1][x].val != WALL)
	{
		add_head_node(queue, create_node(&grid[y - 1][x]));
		grid[y - 1][x].status = WAITING;
	}
	if (grid[y + 1][x].status == SPACE && grid[y + 1][x].val != WALL)
	{
		add_head_node(queue, create_node(&grid[y + 1][x]));
		grid[y + 1][x].status = WAITING;
	}
	if (grid[y][x - 1].status == SPACE && grid[y][x - 1].val != WALL)
	{
		add_head_node(queue, create_node(&grid[y][x - 1]));
		grid[y][x - 1].status = WAITING;
	}
	if (grid[y][x + 1].status == SPACE && grid[y][x + 1].val != WALL)
	{
		add_head_node(queue, create_node(&grid[y][x + 1]));
		grid[y][x + 1].status = WAITING;
	}
}
