/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:05:13 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/27 16:26:55 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	ft_error(char *message)
{
	ft_printf("\033[1;31m" "Error\n" "\033[0m");
	ft_printf("\033[3m\033[2;37m" " %s\n" "\033[0m", message);
	return (0);
}

void	ft_warning(char *message)
{
	ft_printf("\033[1;33m" "Warning\n" "\033[0m");
	ft_printf("\033[3m\033[2;37m" " %s\n" "\033[0m", message);
}

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
	if (!game.collects_imgs.img_0 || !game.collects_imgs.img_1
		|| !game.effect.img)
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
