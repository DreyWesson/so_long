/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:27:09 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/13 22:36:06 by doduwole         ###   ########.fr       */
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

void	set_grid(char **map, t_size *size)
{
	t_cell	**grid;
	int x;
	int y;

	y = 0;
	grid = (t_cell **)malloc(sizeof(t_cell *) * size->row_nbr);
	while (map[y])
	{
		x = 0;
		grid[y] = (t_cell *)malloc(sizeof(t_cell) * size->col_nbr);
		while (map[y][x])
		{
			grid[y][x] = create_cell(map[y][x], x, y);
			x++;
		}
		y++;
	}
	// printf("-> %c %d %d\n", grid[3][6].val, grid[3][6].x_axis, grid[3][6].y_axis);
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
