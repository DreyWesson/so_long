/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:27:09 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/17 09:19:19 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/**
 * [✅] only contains "01CEP"
 * [✅] must contain only one /E/P
 * [✅] all first & last row and first & last cols are 1s ELSE return error
 * [✅] must be rectangular ie the num of cols must be greater than rows
 * [✅] If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way
 * [🔴] check if there’s a valid path in the map.
 * 		make sure all collectibles and exit are accessible
 * 		by checking if its all surrounded by 1s
 */

/**
 * keep all ad
*/



t_cell	create_cell(char s, int x, int y)
{
	t_cell	cell;

	cell.x_axis = x;
	cell.y_axis = y;
	cell.val = s;
	if (s == WALL)
		cell.status = WALL;
	else
		cell.status = RESTING;
	return (cell);
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

void	handle_north(t_cell **grid, t_nodes **queue, t_details *details)
{
	int x;
	int y;

	x = details->pos.x;
	y = details->pos.y;
	if (
		(y - 1) >= 0
		&& grid[y - 1][x].status == RESTING
		&& grid[y - 1][x].val != WALL
		)
	{
		add_head_node(queue, create_node(&grid[y - 1][x]));
		grid[y - 1][x].status = WAITING;
	}
}

void	handle_south(t_cell **grid, t_nodes **queue, t_details *details)
{
	int x;
	int y;
	int row_nbr;

	x = details->pos.x;
	y = details->pos.y;
	row_nbr = details->row_nbr;
	if (
		(y + 1) <= row_nbr 
		&& grid[y + 1][x].status == RESTING
		&& grid[y + 1][x].val != WALL
		)
	{
		add_head_node(queue, create_node(&grid[y + 1][x]));
		grid[y + 1][x].status = WAITING;
	}
}

void	handle_west(t_cell **grid, t_nodes **queue, t_details *details)
{
	int x;
	int y;

	x = details->pos.x;
	y = details->pos.y;
	if (
		(x - 1) >= 0
		&& grid[y][x - 1].status == RESTING
		&& grid[y][x - 1].val != WALL
		)
	{
		add_head_node(queue, create_node(&grid[y][x - 1]));
		grid[y][x - 1].status = WAITING;
	}
}

void	handle_east(t_cell **grid, t_nodes **queue, t_details *details)
{
	int x;
	int y;
	int col_nbr;

	x = details->pos.x;
	y = details->pos.y;
	col_nbr = details->col_nbr;
	if ((x + 1) <= col_nbr
		&& grid[y][x + 1].status == RESTING
		&& grid[y][x + 1].val != WALL
		)
	{
		add_head_node(queue, create_node(&grid[y][x + 1]));
		grid[y][x + 1].status = WAITING;
	}
}

// (void)size;
// check if it's not been visited or waiting
// add to queue
// add its adjacent nodes to queue
// pop the visited from queue
// call with next on queue
// if its equal to resting && not a wall
// del_node(queue);
t_details set_tmp(t_nodes **queue, t_details *details)
{
	t_details tmp;

	tmp.pos.x = (*queue)->cell->x_axis;
	tmp.pos.y = (*queue)->cell->y_axis;
	tmp.col_nbr = details->col_nbr;
	tmp.row_nbr = details->row_nbr;
	return (tmp);
}

void bfs(t_cell **grid,t_nodes **queue, t_cell *curr_node, t_details *details)
{
	t_details tmp;

	details->pos.x = curr_node->x_axis;
	details->pos.y = curr_node->y_axis;
	handle_north(grid, queue, details);
	handle_south(grid, queue, details);
	handle_east(grid, queue, details);
	handle_west(grid, queue, details);
	curr_node->status = VISITED;
	del_node(queue);
	if (!*queue)
		return ;
	tmp = set_tmp(queue, details);
	// print_node(*queue, details->col_nbr);
	// printf("\n");
	bfs(grid, queue, &grid[(*queue)->cell->y_axis][(*queue)->cell->x_axis], &tmp);
}

t_details *default_details(char *ptr)
{
	t_details	*details;

	details = (t_details *)malloc(sizeof(t_details));
	details->col_nbr = 0;
	details->row_nbr = line_counter(ptr);
	return (details);
}

int special_char(char **map)
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
			if (map[y_axis][x_axis] != WALL && map[y_axis][x_axis] != RESTING)
				sum++;
			x_axis++;
		}
		y_axis++;
	}
	// printf("%d\n", sum);
	return (sum);
}

void	handle_map(char **argv)
{
	char		**ptr;
	t_details	*details;
	t_cell		**grid;
	t_nodes		**queue;

	queue = (t_nodes **)ft_calloc(sizeof(t_nodes *), 1);
	details = default_details(argv[1]);
	ptr = map_reader(argv[1], details->row_nbr);
	validate_map(ptr, details);
	grid = create_grid(ptr, details);
	grid[details->pos.y][details->pos.x].status = WAITING;
	add_head_node(queue, create_node(&grid[details->pos.y][details->pos.x]));
	special_char(ptr);
	bfs(grid, queue, &grid[details->pos.y][details->pos.x], details);
	print_grid(grid, *details);
}
/**
 * @bug -> SIZE, GRID, PTR, QUEUE
 * possible leakage
*/
