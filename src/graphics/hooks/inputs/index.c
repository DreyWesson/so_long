/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 03:02:51 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/30 09:37:09 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/so_long.h"

/* Input management. Called each time a key is pressed. */
int	input(int key, t_game *game)
{
	int	moved;

	if (key == ESC)
		end_program(game);
	else if (key == RESET)
		return (reset(game));
	if (game->player.tile == NULL)
		return (0);
	if (key == KEY_UP)
		moved = move_player(game, game->player.tile->up);
	else if (key == KEY_DOWN)
		moved = move_player(game, game->player.tile->down);
	else if (key == KEY_LEFT)
		moved = move_player(game, game->player.tile->left);
	else if (key == KEY_RIGHT)
		moved = move_player(game, game->player.tile->right);
	else
		return (0);
	if (moved)
		printf("Moves: %02d\n", ++game->moves);
	return (1);
}
