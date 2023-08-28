/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:13:34 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/28 11:34:49 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

t_bool	draw_corner(t_game game)
{
	t_cell	cell;
	t_axis	pos;

	cell = game.current_cell;
	pos = cell.position;
	if (cell.position.x == 0
		&& cell.position.y == 0)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.north_west, pos.x, pos.y);
	else if (cell.position.x == 0
		&& cell.position.y == game.wndw_size.y - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.south_west, pos.x, pos.y);
	else if (cell.position.x == game.wndw_size.x - IMG_SIZE
		&& cell.position.y == 0)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.north_east, pos.x, pos.y);
	else if (cell.position.x == game.wndw_size.x - IMG_SIZE
		&& cell.position.y == game.wndw_size.y - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.south_east, pos.x, pos.y);
	else
		return (FALSE);
	return (TRUE);
}

t_bool	draw_sides(t_game game)
{
	t_cell	cell;
	t_axis	pos;

	cell = game.current_cell;
	pos = cell.position;
	if (cell.position.x == 0)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.west, pos.x, pos.y);
	else if (cell.position.x == game.wndw_size.x - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.east, pos.x, pos.y);
	else if (cell.position.y == 0)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.north, pos.x, pos.y);
	else if (cell.position.y == game.wndw_size.y - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.south, pos.x, pos.y);
	else
		return (FALSE);
	return (TRUE);
}

// /* Draws the corresponding sprite for the wall at <pos> */
void	draw_wall(t_game game)
{
	t_cell	cell;
	t_axis	pos;

	cell = game.current_cell;
	pos = cell.position;
	if (draw_corner(game))
		return ;
	else if (draw_sides(game))
		return ;
	mlx_put_image_to_window(game.mlx, game.window,
		game.wall_imgs.block, pos.x, pos.y);
}