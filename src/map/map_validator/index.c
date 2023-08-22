/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:44:42 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/22 21:31:54 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

int	validate_map(char **map, t_details *details, t_game *game, t_nodes **queue)
{
	int		y_axis;
	int		x_axis;
	t_quant	*quant;
	t_cell	**grid;

	y_axis = 0;
	quant = (t_quant *)malloc(sizeof(t_quant));
	default_quant(quant);
	while (map[y_axis])
	{
		x_axis = 0;
		while (map[y_axis][x_axis])
		{
			validate_composition(map[y_axis][x_axis], quant);
			validate_walls(map[y_axis], details->row_nbr, x_axis, y_axis);
			if (map[y_axis][x_axis] == 'P')
				save_start(y_axis, x_axis, details);
			x_axis++;
		}
		validate_shape(details, y_gaaaxis, x_axis);
		y_axis++;
	}
	check_quant(quant, details);
	grid = create_grid(map, details, game);
	if (validate_paths(grid, queue, *details) != special_char(map))
		return (ft_error("Invalid path(s)"));
	return (1);
}
/**
 * @bug -> quant
 * possible leakage
*/