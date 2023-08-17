/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:27:09 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/17 23:38:46 by doduwole         ###   ########.fr       */
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
		cell.status = SPACE;
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

t_details set_tmp(t_nodes **queue, t_details *details)
{
	t_details tmp;

	tmp.pos.x = (*queue)->cell->x_axis;
	tmp.pos.y = (*queue)->cell->y_axis;
	tmp.col_nbr = details->col_nbr;
	tmp.row_nbr = details->row_nbr;
	return (tmp);
}

int bfs(t_cell **grid,t_nodes **queue, t_details *details)
{
	t_details tmp;
	int memo;

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

t_details *default_details(char *ptr)
{
	t_details	*details;

	details = (t_details *)malloc(sizeof(t_details));
	details->col_nbr = 0;
	details->row_nbr = line_counter(ptr);
	return (details);
}

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
			if (map[y_axis][x_axis] != WALL && map[y_axis][x_axis] != SPACE)
				sum++;
			x_axis++;
		}
		y_axis++;
	}
	return (sum);
}

void	handle_map(char **argv)
{
	char		**ptr;
	t_details	*props;
	t_cell		**grid;
	t_nodes		**queue;
	int			found;

	queue = (t_nodes **)ft_calloc(sizeof(t_nodes *), 1);
	props = default_details(argv[1]);
	ptr = map_reader(argv[1], props->row_nbr);
	validate_map(ptr, props);
	grid = create_grid(ptr, props);
	grid[props->pos.y][props->pos.x].status = WAITING;
	add_head_node(queue, create_node(&grid[props->pos.y][props->pos.x]));
	found = bfs(grid, queue, props);
	// printf("%d %d\n", found, special_char(ptr));
	if (found != special_char(ptr))
		ft_error("Invalid path(s)");
	// print_grid(grid, *props);
}
/**
 * @bug -> SIZE, GRID, PTR, QUEUE
 * possible leakage
*/
