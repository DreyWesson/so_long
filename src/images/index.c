/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:08:40 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/29 02:47:55 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	door_imgs(t_game *game, int *x, int *y)
{
	game->door_open_img = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/door_01.xpm", x, y);
	game->door_close_img = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/door_02.xpm", x, y);
	door_imgs_error(*game);
}

static void	collectible_imgs(t_game *game, int *x, int *y)
{
	game->collects_imgs.img_0 = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/plant_03.xpm", x, y);
	game->collects_imgs.img_1 = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/plant_04.xpm", x, y);
	game->collects_imgs.current_img = game->collects_imgs.img_0;
	game->effect.img = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/effect_w.xpm", x, y);
	collectible_imgs_error(*game);
}

static void	player_imgs(t_game *game, int *x, int *y)
{
	game->player.idle_img_0 = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/player_01.xpm", x, y);
	game->player.idle_img_1 = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/player_02.xpm", x, y);
	game->player.action_img = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/player_03.xpm", x, y);
	game->player.current_img = game->player.action_img;
	player_imgs_error(*game);
}

void	open_images(t_game *game)
{
	int	*x;
	int	*y;

	x = &game->img_size.x;
	y = &game->img_size.y;
	north_wall(game, x, y);
	south_wall(game, x, y);
	west_wall(game, x, y);
	east_wall(game, x, y);
	player_imgs(game, x, y);
	collectible_imgs(game, x, y);
	door_imgs(game, x, y);
}