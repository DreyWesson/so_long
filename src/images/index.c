/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:08:40 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/27 15:18:42 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	door_imgs_error(t_game game)
{
	if (!game.door_close_img)
		printf("door_01.xpm file not opening\n");
	if (!game.door_open_img)
		printf("door_02.xpm file not opening\n");
	if (!game.door_close_img || !game.door_open_img)
		exit(1);
}

void	collect_imgs_error(t_game game)
{
	if (!game.collects_imgs.img_0)
		printf("plant_03.xpm file not opening\n");
	if (!game.collects_imgs.img_1)
		printf("plant_04.xpm file not opening\n");
	if (!game.effect.img)
		printf("effect_w.xpm file not opening\n");
	if (!game.collects_imgs.img_0 || !game.collects_imgs.img_1 || !game.effect.img)
		exit(1);
}

void	player_imgs_error(t_game game)
{
	if (!game.player.idle_img_0)
		printf("player_01.xpm file not opening\n");
	if (!game.player.idle_img_1)
		printf("player_02.xpm file not opening\n");
	if (!game.player.action_img)
		printf("player_03.xpm file not opening\n");
	if (!game.player.idle_img_0 || !game.player.idle_img_1
		|| !game.player.action_img)
		exit(1);
}

static void	open_door_imgs(t_game *game)
{
	game->door_open_img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/door_01.xpm",
			&game->img_size.x, &game->img_size.y);
	game->door_close_img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/door_02.xpm",
			&game->img_size.x, &game->img_size.y);
	door_imgs_error(*game);
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
	collect_imgs_error(*game);
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
	player_imgs_error(*game);
}

void	open_images(t_game *game)
{
	open_wallimgs_up(game);
	open_wallimgs_down(game);
	open_player_imgs(game);
	open_collect_imgs(game);
	open_door_imgs(game);
}