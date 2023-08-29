/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 07:33:36 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/29 17:17:10 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

void	west_wall(t_game *game, int *x, int *y)
{
	game->wall_imgs.west = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/west_wall.xpm", x, y);
	west_wall_error(game->wall_imgs);
}

void	east_wall(t_game *game, int *x, int *y)
{
	game->wall_imgs.east = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/east_wall.xpm", x, y);
	east_wall_error(game->wall_imgs);
}

void	south_wall(t_game *game, int *x, int *y)
{
	game->wall_imgs.south = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/south_wall.xpm", x, y);
	game->wall_imgs.south_east = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/south_east.xpm", x, y);
	game->wall_imgs.south_west = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/south_west.xpm", x, y);
	south_wall_error(game->wall_imgs);
}

void	north_wall(t_game *game, int *x, int *y)
{
	game->wall_imgs.north = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/north_wall.xpm", x, y);
	game->wall_imgs.block = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/wall.xpm", x, y);
	game->wall_imgs.north_west = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/north_west.xpm", x, y);
	game->wall_imgs.north_east = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/north_east.xpm", x, y);
	north_wall_error(game->wall_imgs);
}
