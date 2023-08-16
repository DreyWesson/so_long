/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:27:09 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/16 22:50:21 by doduwole         ###   ########.fr       */
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

void	print_grid(t_cell **grid, t_size size)
{
	int	x;
	int	y;

	y = 0;
	while (y < size.row_nbr)
	{
		x = 0;
		while (x < size.col_nbr)
		{
			printf(
				"[%c->(%d, %d)], ",
				grid[y][x].val,
				grid[y][x].y_axis,
				grid[y][x].x_axis
				);
			x++;
		}
		printf("\n");
		y++;
	}
}


t_cell	**create_grid(char **map, t_size *size)
{
	int		x;
	int		y;
	t_cell	**grid;

	y = 0;
	grid = (t_cell **)ft_calloc(sizeof(t_cell *), size->row_nbr);
	while (y < size->row_nbr)
	{
		x = 0;
		grid[y] = (t_cell *)ft_calloc(sizeof(t_cell), size->col_nbr);
		while (x < size->col_nbr)
		{
			grid[y][x] = create_cell(map[y][x], x, y);
			x++;
		}
		y++;
	}
	return (grid);
}

void handle_north(t_cell **grid, t_nodes **queue, t_cell *curr_node)
{
	if (
		curr_node->y_axis - 1 >= 0 
			&& grid[curr_node->y_axis - 1][curr_node->x_axis].status == RESTING
			&& grid[curr_node->y_axis - 1][curr_node->x_axis].val != WALL
		) // NORTH
	{
		add_head_node(queue, create_node(&grid[curr_node->y_axis - 1][curr_node->x_axis]));
	}
}

void handle_south(t_cell **grid, t_nodes **queue, t_cell *curr_node, t_size *size)
{
	if (
		curr_node->y_axis + 1 <= size->row_nbr 
			&& grid[curr_node->y_axis + 1][curr_node->x_axis].status == RESTING
			&& grid[curr_node->y_axis + 1][curr_node->x_axis].val != WALL
		) // SOUTH
	{
		add_head_node(queue, create_node(&grid[curr_node->y_axis + 1][curr_node->x_axis]));
	}
}
void handle_west(t_cell **grid, t_nodes **queue, t_cell *curr_node)
{
	if (
		curr_node->x_axis - 1 >= 0
			&& grid[curr_node->y_axis][curr_node->x_axis - 1].status == RESTING
			&& grid[curr_node->y_axis][curr_node->x_axis - 1].val != WALL
		) // WEST
	{
		add_head_node(queue, create_node(&grid[curr_node->y_axis][curr_node->x_axis - 1]));
	}
}

void handle_east(t_cell **grid, t_nodes **queue, t_cell *curr_node, t_size *size)
{
	if (
		curr_node->x_axis + 1 <= size->col_nbr
			&& grid[curr_node->y_axis][curr_node->x_axis + 1].status == RESTING
			&& grid[curr_node->y_axis][curr_node->x_axis + 1].val != WALL
		) // EAST
	{
		add_head_node(queue, create_node(&grid[curr_node->y_axis][curr_node->x_axis + 1]));
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
void bfs(t_cell **grid,t_nodes **queue, t_cell *curr_node, t_size *size)
{
	if (!*queue)
		return ;
	handle_north(grid, queue, curr_node);
	handle_south(grid, queue, curr_node, size);
	handle_east(grid, queue, curr_node, size);
	handle_west(grid, queue, curr_node);
	curr_node->status = VISITED;
	(void)size;
}

void	handle_map(char **argv)
{
	char	**ptr;
	t_size	*size;
	t_cell	**grid;
	t_nodes	**queue;

	size = (t_size *)malloc(sizeof(t_size));
	queue = (t_nodes **)ft_calloc(sizeof(t_nodes *), 1);
	size->col_nbr = 0;
	size->row_nbr = line_counter(argv[1]);
	ptr = map_reader(argv[1], size->row_nbr);
	validate_map(ptr, size);
	grid = create_grid(ptr, size);
	grid[size->start_pos.y][size->start_pos.x].status = WAITING;
	add_head_node(queue,
		create_node(&grid[size->start_pos.y][size->start_pos.x]));
	bfs(grid, queue, &grid[size->start_pos.y][size->start_pos.x], size);
	print_node(*queue, size->col_nbr);
}
	/**
	 * @bug -> SIZE, GRID, PTR, LIST
	 * possible leakage
	*/
