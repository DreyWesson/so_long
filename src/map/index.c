/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:27:09 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/13 18:16:12 by doduwole         ###   ########.fr       */
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

void	grid_detailing(char **map, t_size *size)
{
	t_cell	cell;
	t_coord axis;
	t_cell  **cells;

	axis.y = 0;
	cells = (t_cell **)malloc(sizeof(t_cell*) * size->row_nbr);
	while (map[axis.y])
	{
		axis.x = 0;
		cells[axis.y] = (t_cell *)malloc(sizeof(t_cell) * size->col_nbr);
		while (map[axis.y][axis.x])
		{
			cell.pos = &axis;
			cell.val = map[axis.y][axis.x];
			cell.status = READY;
			cells[axis.y][axis.x] = cell;
			axis.x++;
		}
		axis.y++;
	}
	printf("%c\n", cells[3][1].val);
}

void	handle_map(char **argv)
{
	char	**ptr;
	t_size 	*size;

	size = (t_size *)malloc(sizeof(t_size));
	size->col_nbr = 0;
	size->row_nbr = line_counter(argv[1]);
	ptr = map_reader(argv[1], size->row_nbr);
	validate_map(ptr, size->row_nbr, &size->col_nbr);
	grid_detailing(ptr, size);
	printf("%d %d\n", size->row_nbr, size->col_nbr);
}
