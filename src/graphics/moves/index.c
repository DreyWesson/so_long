/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 07:32:27 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/29 22:30:11 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

void	to_collectible(t_game *game, t_cell *tile)
{
	tile->type = EMPTY;
	game->collects--;
	effect_anime(&game->effect, tile->position);
	action_anime(&game->player);
}

void	to_exit(t_game *game, t_cell *tile)
{
	effect_anime(&game->effect, tile->position);
	remove_player(game);
	game->collects = -1;
	printf("Great job!\n");
	end_program(game);
}

void	to_empty(t_game *game, t_cell *tile)
{
	tile->type = PLAYER;
	if (game->player.tile->type != EXIT)
		game->player.tile->type = EMPTY;
	game->player.tile = tile;
}

int	move_player(t_game *game, t_cell *tile)
{
	if (tile->type == EMPTY)
		to_empty(game, tile);
	else if (tile->type == COLLECTABLE)
		to_collectible(game, tile);
	else if (tile->type == EXIT && game->collects <= 0)
		to_exit(game, tile);
	else
		return (0);
	return (1);
}
