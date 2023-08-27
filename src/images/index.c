/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:08:40 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/27 12:18:50 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"


static void	open_door_imgs(t_game *game)
{
	game->door_open_img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/door_01.xpm",
			&game->img_size.x, &game->img_size.y);
	game->door_close_img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/door_02.xpm",
			&game->img_size.x, &game->img_size.y);
}

static void	open_collect_imgs(t_game *game)
{
	game->collects_imgs.img_0 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/plant_03.xpm",
			&game->img_size.x, &game->img_size.y);
	game->collects_imgs.img_1 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/plant_04.xpm",
			&game->img_size.x, &game->img_size.y);
	game->collects_imgs.current_img = game->collects_imgs.img_0;
	game->effect.img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/effect_w.xpm",
			&game->img_size.x, &game->img_size.y);
}

static void	open_player_imgs(t_game *game)
{
	game->player.idle_img_0 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/player_01.xpm", &game->img_size.x, &game->img_size.y);
	game->player.idle_img_1 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/player_02.xpm", &game->img_size.x, &game->img_size.y);
	game->player.action_img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/player_03.xpm", &game->img_size.x, &game->img_size.y);
	game->player.current_img = game->player.action_img;
}

void	open_images(t_game *game)
{
	open_wallimgs_up(game);
	open_wallimgs_down(game);
	open_player_imgs(game);
	open_collect_imgs(game);
	open_door_imgs(game);
}