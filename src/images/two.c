/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 07:33:36 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/28 11:40:52 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	south_wall_error(t_wall_img wall)
{
	if (!wall.south_east)
		printf("wall_dr.xpm file not opening\n");
	if (!wall.south)
		printf("wall_d.xpm file not opening\n");
	if (!wall.south_west)
		printf("wall_dl.xpm file not opening\n");
	if (!wall.west)
		printf("wall_l.xpm file not opening\n");
	if (!wall.south_east || !wall.south || !wall.south_west || !wall.west)
		exit(1);
}

void	north_wall_error(t_wall_img wall)
{
	if (!wall.block)
		printf("wall_02.xpm file not opening\n");
	if (!wall.north_west)
		printf("wall_ul.xpm file not opening\n");
	if (!wall.north)
		printf("wall_u.xpm file not opening\n");
	if (!wall.north_east)
		printf("wall_ur.xpm file not opening\n");
	if (!wall.east)
		printf("wall_r.xpm file not opening\n");
	if (!wall.block || !wall.north_west || !wall.north || !wall.north_east
		|| !wall.east)
		exit(1);
}

void	south_wall(t_game *game)
{
	game->wall_imgs.south_east = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/wall_dr.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.south = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/wall_d.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.south_west = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/wall_dl.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.west = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/wall_l.xpm",
			&game->img_size.x, &game->img_size.y);
	south_wall_error(game->wall_imgs);
}

void	north_wall(t_game *game)
{
	game->wall_imgs.block = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/wall_02.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.north_west = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/wall_ul.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.north = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/wall_u.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.north_east = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/wall_ur.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.east = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/wall_r.xpm",
			&game->img_size.x, &game->img_size.y);
	north_wall_error(game->wall_imgs);
}