/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:44:42 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/22 20:08:57 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

t_cell	**validate_map(char **map, t_details *details, t_game *game)
{
	int		y_axis;
	int		x_axis;
	t_quant	*quant;

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
		validate_shape(details, y_axis, x_axis);
		y_axis++;
	}
	check_quant(quant, details);
	return (create_grid(map, details, game));
}
/**
 * @bug -> quant
 * possible leakage
*/