/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:44:42 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/28 10:46:58 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

t_cell	**validate_map(char **map, t_details *details, t_nodes **queue)
{
	int		y_axis;
	int		x_axis;
	t_quant	quant;
	t_cell	**grid;

	y_axis = 0;
	default_quant(&quant);
	while (map[y_axis])
	{
		x_axis = 0;
		while (map[y_axis][x_axis])
		{
			if (!validate_composition(map[y_axis][x_axis], &quant)
			|| !validate_walls(map[y_axis], details->row_nbr, x_axis, y_axis))
				return (0);
			if (map[y_axis][x_axis] == 'P')
				save_start(y_axis, x_axis, details);
			x_axis++;
		}
		if (!validate_shape(details, y_axis, x_axis))
			return (0);
		y_axis++;
	}
	check_quant(&quant, details);
	grid = create_grid(map, details);
	if (validate_paths(grid, queue, *details) != special_char(map))
	{
		free_grid(grid, details->row_nbr);
		ft_error("Invalid path(s)");
		return (NULL);
	}
	// print_grid(grid, *details);
	// print_adjacent(*details, game->grid);
	return (grid);
}
/**
 * @bug -> quant
 * possible leakage
*/