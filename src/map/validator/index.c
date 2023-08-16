/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:44:42 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/16 09:41:52 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

void	validate_map(char **map, t_size *size)
{
	int		y_axis;
	int		x_axis;
	t_quant	*quant;
	// t_coord	start_pos;

	y_axis = 0;
	quant = (t_quant *)malloc(sizeof(t_quant));
	default_quant(quant);
	while (map[y_axis])
	{
		x_axis = 0;
		while (map[y_axis][x_axis])
		{
			validate_composition(map[y_axis][x_axis], quant);
			validate_walls(map[y_axis], size->row_nbr, x_axis, y_axis);
			if (map[y_axis][x_axis] == 'P')
				size->start_pos = save_start(y_axis, x_axis);
			x_axis++;
		}
		validate_shape(size, y_axis, x_axis);
		y_axis++;
	}
	// (void)start_pos;
	check_quant(quant);
	/**
	 * @bug -> quant
	 * possible leakage
	*/
}