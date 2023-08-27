/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 07:29:39 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/27 16:24:35 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/so_long.h"

static void	player_animation(t_player *player)
{
	if (player->current_img == player->action_img
		&& player->framecount >= player->action_frames)
		player->current_img = player->idle_img_1;
	else if (player->framecount == player->idle_frames)
		player->current_img = player->idle_img_0;
	else if (player->framecount >= player->idle_frames * 2)
	{
		player->current_img = player->idle_img_1;
		player->framecount = 0;
	}
	player->framecount += 1;
}

static void	collec_animation(t_collect_img *img)
{
	static int	frame;

	if (img->anim_frames == 0)
		return ;
	if (frame == img->anim_frames)
		img->current_img = img->img_0;
	else if (frame >= img->anim_frames * 2)
	{
		img->current_img = img->img_1;
		frame = 0;
	}
	frame += 1;
}

static void	effect_animation(t_effect *effect)
{
	if (effect->counter < effect->frames)
		effect->counter++;
}

/* Calculates all animations and render.
* Called once each frame */
int	update(t_game *game)
{
	player_animation(&game->player);
	collec_animation(&game->collects_imgs);
	effect_animation(&game->effect);
	render(*game);
	return (1);
}