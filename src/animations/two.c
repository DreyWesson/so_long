/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 08:57:02 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/24 08:57:44 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/* Places and starts the "particles" effect */
void	effect_anim(t_effect *effect, t_axis pos)
{
	effect->counter = 0;
	effect->pos = pos;
}

/* Starts the action pose animation of the player */
void	action_anim(t_player *player)
{
	player->framecount = 0;
	player->current_img = player->action_img;
}