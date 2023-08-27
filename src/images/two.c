/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 07:33:36 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/27 12:23:09 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"


void	open_wallimgs_down(t_game *game)
{
	game->wall_imgs.down_right = mlx_xpm_file_to_image(game->mlx,
			"./sprites/wall_dr.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.down = mlx_xpm_file_to_image(game->mlx,
			"./sprites/wall_d.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.down_left = mlx_xpm_file_to_image(game->mlx,
			"./sprites/wall_dl.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.left = mlx_xpm_file_to_image(game->mlx,
			"./sprites/wall_l.xpm",
			&game->img_size.x, &game->img_size.y);
}

void	open_wallimgs_up(t_game *game)
{
	game->wall_imgs.block = mlx_xpm_file_to_image(game->mlx,
			"./sprites/wall_02.xpm",
			&game->img_size.x, &game->img_size.y);
	printf("%d %d\n",game->img_size.x, game->img_size.y);
	if (!game->wall_imgs.block)
		printf("debug\n");
	game->wall_imgs.up_left = mlx_xpm_file_to_image(game->mlx,
			"./sprites/wall_ul.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.up = mlx_xpm_file_to_image(game->mlx,
			"./sprites/wall_u.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.up_right = mlx_xpm_file_to_image(game->mlx,
			"./sprites/wall_ur.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.right = mlx_xpm_file_to_image(game->mlx,
			"./sprites/wall_r.xpm",
			&game->img_size.x, &game->img_size.y);
}