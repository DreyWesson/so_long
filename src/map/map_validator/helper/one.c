/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:29:43 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/21 15:00:35 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/so_long.h"

void	validate_composition(char s, t_quant *quant)
{
	char	*set;

	set = "01CEP";
	if (!ft_strchr(set, s))
	{
		ft_error("Invalid composition");
		exit(0);
	}
	else
	{
		if (s == 'C')
			(*quant).collectibles += 1;
		else if (s == 'E')
			(*quant).exit += 1;
		else if (s == 'P')
			(*quant).player += 1;
	}
}

void	validate_walls(char *s, int row_nbr, int j, int i)
{
	if (s[j] != '1' && (i == 0 || i == row_nbr - 1
			|| j == 0 || s[j + 1] == '\0'))
	{
		ft_error("Should be surrounded by walls");
		exit(0);
	}
}

void	validate_shape(t_details *details, int i, int j)
{
	if (i == 0)
		details->col_nbr = j;
	if (j == details->row_nbr || (*details).col_nbr != j)
	{
		ft_error("Provide rectangular maps only");
		exit(0);
	}
}

void	save_start(int y, int x, t_details *details)
{
	details->pos.y = y;
	details->pos.x = x;
}

void	check_quant(t_quant *quant)
{
	if (quant->collectibles < 1 || quant->exit != 1 || quant->player != 1)
	{
		ft_error("Invalid composition quantity");
		exit(0);
	}
}
