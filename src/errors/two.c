/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 02:25:36 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/29 12:01:49 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	south_wall_error(t_wall_img wall)
{
	if (!wall.south_east)
		printf("south_east.xpm file not opening\n");
	if (!wall.south)
		printf("south_wall.xpm file not opening\n");
	if (!wall.south_west)
		printf("south_west.xpm file not opening\n");
	// if (!wall.south_east || !wall.south || !wall.south_west)
	// 	exit(1);
}

void	north_wall_error(t_wall_img wall)
{
	if (!wall.block)
		printf("wall_02.xpm file not opening\n");
	if (!wall.north_west)
		printf("north_west.xpm file not opening\n");
	if (!wall.north)
		printf("north.xpm file not opening\n");
	if (!wall.north_east)
		printf("north_east.xpm file not opening\n");
	if (!wall.east)
		printf("east_wall.xpm file not opening\n");
	// if (!wall.block || !wall.north_west || !wall.north || !wall.north_east)
	// 	exit(1);
}

void	east_wall_error(t_wall_img wall)
{
	if (!wall.east)
	{
		printf("east_wall.xpm file not opening\n");
		exit(1);
	}
}

void	west_wall_error(t_wall_img wall)
{
	if (!wall.west)
	{
		printf("west_wall.xpm file not opening\n");
		exit(1);
	}
}