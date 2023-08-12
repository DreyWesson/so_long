/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:44:42 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/12 22:07:39 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

void	validate_map(char **map, int line_nbr)
{
	int		y_axis;
	int		x_axis;
	int		col_nbr;
	t_quant	*quant;
	t_coord	start_pos;

	y_axis = 0;
	col_nbr = 0;
	quant = (t_quant *)malloc(sizeof(t_quant));
	default_quant(quant);
	while (map[y_axis])
	{
		x_axis = 0;
		while (map[y_axis][x_axis])
		{
			validate_composition(map[y_axis][x_axis], quant);
			validate_walls(map[y_axis], line_nbr, x_axis, y_axis);
			if (map[y_axis][x_axis] == 'P')
				start_pos = save_start(y_axis, x_axis);
			x_axis++;
		}
		validate_shape(line_nbr, &col_nbr, y_axis, x_axis);
		y_axis++;
	}
	(void)start_pos;
	printf("%d %d\n", start_pos.x, start_pos.y);
	check_quant(quant);
}