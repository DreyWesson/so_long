/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:27:09 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/14 06:42:04 by doduwole         ###   ########.fr       */
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
 * When you encounter C/E make sure P can access it
 * check if P is above or below or same line
 * check if the next lines are not sealed
*/
t_cell create_cell(char s, int x, int y)
{
	t_cell	cell;

	cell.x_axis = x;
	cell.y_axis = y;
	cell.val = s;
	cell.status = READY;
	return (cell);
}

void print_grid(t_cell **grid, t_size size)
{
	int	x;
	int	y;

	y = 0;
	while (y < size.row_nbr)
	{
		x = 0;
		while (x < size.col_nbr)
		{
			printf("[%c->(%d, %d)], ", grid[y][x].val, grid[y][x].y_axis, grid[y][x].x_axis);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	set_grid(char **map, t_size *size)
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
	print_grid(grid, *size);
}

void	handle_map(char **argv)
{
	char	**ptr;
	t_size	*size;

	size = (t_size *)malloc(sizeof(t_size));
	size->col_nbr = 0;
	size->row_nbr = line_counter(argv[1]);
	ptr = map_reader(argv[1], size->row_nbr);
	validate_map(ptr, size->row_nbr, &size->col_nbr);
	set_grid(ptr, size);
}
