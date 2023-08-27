/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 07:32:27 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/27 22:04:39 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/so_long.h"

void	pick_collect(t_game *game, t_cell *tile)
{
	tile->type = EMPTY;
	printf("->%d\n", game->collects);
	game->collects--;
	effect_anim(&game->effect, tile->position);
	action_anim(&game->player);
}

void	move_to_exit(t_game *game, t_cell *tile)
{
	effect_anim(&game->effect, tile->position);
	mlx_put_image_to_window(game->mlx, game->window, game->white_panel, 0, 0);
	remove_player(game);
	game->collects = -1;
}
void	move_to_empty(t_game *game, t_cell *tile)
{
	tile->type = PLAYER;
	if (game->player.tile->type != EXIT)
		game->player.tile->type = EMPTY;
	game->player.tile = tile;
}

t_bool	move_to(t_game *game, t_cell *tile)
{

	if (tile->type == EMPTY)
		move_to_empty(game, tile);
	else if (tile->type == COLLECTABLE)
		pick_collect(game, tile);
	else if (tile->type == EXIT && game->collects <= 0)
		move_to_exit(game, tile);
	else
		return (FALSE);
	return (TRUE);
}

