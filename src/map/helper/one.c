/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 06:24:00 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/24 17:51:35 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

t_cell	create_cell(char s, int x, int y)
{
	t_cell	cell;

// printf("%d %d\n", y, x);
	cell.x_axis = x;
	cell.y_axis = y;
	cell.val = s;
	cell.og_type = s;
	cell.position.x = x * IMG_SIZE;
	cell.position.y = y * IMG_SIZE;
	// cell.up = NULL;
	// cell.down = NULL;
	// cell.left = NULL;
	// cell.right = NULL;
	if (s == BLOCK)
		cell.status = WALL;
	else
		cell.status = EMPTY;
	return (cell);
}

t_details	default_details(char *ptr)
{
	t_details	details;

	details.col_nbr = 0;
	details.row_nbr = line_counter(ptr);
	return (details);
}



void	print_grid(t_cell **grid, t_details details)
{
	int	x;
	int	y;

	y = 0;
	while (y < details.row_nbr)
	{
		x = 0;
		while (x < details.col_nbr)
		{
			printf(
				"[%c->(%d, %d, %c)],		",
				grid[y][x].val,
				grid[y][x].y_axis,
				grid[y][x].x_axis,
				grid[y][x].status
				);
			x++;
		}
		printf("\n\n");
		y++;
	}
}

// t_details	set_tmp(t_nodes **queue, t_details *details)
// {
// 	t_details	tmp;

// 	tmp.pos.x = (*queue)->cell->x_axis;
// 	tmp.pos.y = (*queue)->cell->y_axis;
// 	tmp.col_nbr = details->col_nbr;
// 	tmp.row_nbr = details->row_nbr;
// 	return (tmp);
// }

int	special_char(char **map)
{
	int	y_axis;
	int	x_axis;
	int	sum;

	y_axis = 0;
	sum = 0;
	while (map[y_axis])
	{
		x_axis = 0;
		while (map[y_axis][x_axis])
		{
			if (map[y_axis][x_axis] != BLOCK && map[y_axis][x_axis] != SPACE)
				sum++;
			x_axis++;
		}
		y_axis++;
	}
	return (sum);
}
