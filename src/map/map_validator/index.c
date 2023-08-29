/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:44:42 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/29 16:53:35 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

t_cell	**validate_map(char **map, t_details *details, t_nodes **queue)
{
	int		y_axis;
	int		x_axis;
	t_quant	quant;

	y_axis = 0;
	default_quant(&quant);
	while (map[y_axis])
	{
		x_axis = 0;
		while (map[y_axis][x_axis])
		{
			if (!validate_composition(map[y_axis][x_axis], &quant)
			|| !validate_walls(map[y_axis], details->row_nbr, x_axis, y_axis))
				return (NULL);
			if (map[y_axis][x_axis] == 'P')
				save_start(y_axis, x_axis, details);
			x_axis++;
		}
		if (!validate_shape(details, y_axis, x_axis))
			return (NULL);
		y_axis++;
	}
	check_quant(&quant, details);
	return (validate_paths(create_grid(map, details), queue, *details, map));
}
