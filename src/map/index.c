/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:27:09 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/13 09:27:16 by doduwole         ###   ########.fr       */
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

void	grid_detailing(char **map, int row_nbr, int col_nbr)
{
	t_cell	*cell;
	int		x_axis;
	int		y_axis;
	t_cell  **cells;

	x_axis = 0;
	y_axis = 0;
	cell = (t_cell *)malloc(sizeof(t_cell));
	// cells = NULL;
	while (map[y_axis])
	{
		x_axis = 0;
		while (map[y_axis][x_axis])
		{
			cell->pos->x = x_axis;
			cell->pos->y = y_axis;
			cell->val = map[y_axis][x_axis];
			cell->status = READY;
			x_axis++;
		}
		y_axis++;
	}
	
	(void)cells;
	(void)row_nbr;
	(void)col_nbr;
}

void	handle_map(char **argv)
{
	char	**ptr;
	int		row_nbr;
	int		col_nbr;

	col_nbr = 0;
	row_nbr = line_counter(argv[1]);
	ptr = map_reader(argv[1], row_nbr);
	validate_map(ptr, row_nbr, &col_nbr);
	// grid_detailing(ptr, row_nbr, col_nbr);

}
