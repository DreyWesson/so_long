/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 07:33:36 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/27 14:59:24 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	downwall_imgs_error(t_wall_img wall)
{
	if (!wall.down_right)
		printf("wall_dr.xpm file not opening\n");
	if (!wall.down)
		printf("wall_d.xpm file not opening\n");
	if (!wall.down_left)
		printf("wall_dl.xpm file not opening\n");
	if (!wall.left)
		printf("wall_l.xpm file not opening\n");
	if (!wall.down_right || !wall.down || !wall.down_left || !wall.left)
		exit(1);
}

void	upwall_imgs_error(t_wall_img wall)
{
	if (!wall.block)
		printf("wall_02.xpm file not opening\n");
	if (!wall.up_left)
		printf("wall_ul.xpm file not opening\n");
	if (!wall.up)
		printf("wall_u.xpm file not opening\n");
	if (!wall.up_right)
		printf("wall_ur.xpm file not opening\n");
	if (!wall.right)
		printf("wall_r.xpm file not opening\n");
	if (!wall.block || !wall.up_left || !wall.up || !wall.up_right
		|| !wall.right)
		exit(1);
}

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
	downwall_imgs_error(game->wall_imgs);
}

void	open_wallimgs_up(t_game *game)
{
	game->wall_imgs.block = mlx_xpm_file_to_image(game->mlx,
			"./sprites/wall_02.xpm",
			&game->img_size.x, &game->img_size.y);
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
	upwall_imgs_error(game->wall_imgs);
}