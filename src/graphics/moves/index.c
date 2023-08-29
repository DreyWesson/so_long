/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 07:32:27 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/29 22:14:59 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

void	pick_collect(t_game *game, t_cell *tile)
{
	tile->type = EMPTY;
	game->collects--;
	effect_anime(&game->effect, tile->position);
	action_anime(&game->player);
}

void	move_to_exit(t_game *game, t_cell *tile)
{
	effect_anime(&game->effect, tile->position);
	remove_player(game);
	game->collects = -1;
	printf("Great job!\n");
	end_program(game);
}

void	move_to_empty(t_game *game, t_cell *tile)
{
	tile->type = PLAYER;
	if (game->player.tile->type != EXIT)
		game->player.tile->type = EMPTY;
	game->player.tile = tile;
}

int	move_to(t_game *game, t_cell *tile)
{
	if (tile->type == EMPTY)
		move_to_empty(game, tile);
	else if (tile->type == COLLECTABLE)
		pick_collect(game, tile);
	else if (tile->type == EXIT && game->collects <= 0)
		move_to_exit(game, tile);
	else
		return (0);
	return (1);
}
