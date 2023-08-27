/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 07:30:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/25 12:30:57 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	reset(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->props.row_nbr)
	{
		x = 0;
		while (x < game->props.col_nbr)
		{
			game->grid[y][x].type = game->grid[y][x].og_type;
			if (game->grid[y][x].type == PLAYER)
				game->player.tile = &game->grid[y][x];
			x++;
		}
		y++;
	}
	game->moves = 0;
	game->collects = game->og_collects;
	mlx_put_image_to_window(game->mlx, game->window, game->white_panel, 0, 0);
	return (0);
}

// /* Returns the game to its original state */
// int	reset(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (game->grid[y] != NULL)
// 	{
// 		x = 0;
// 		while (game->grid[y][x].type != 0)
// 		{
// 			game->grid[y][x].type = game->grid[y][x].og_type;
// 			if (game->grid[y][x].type == PLAYER)
// 				game->player.tile = &game->grid[y][x];
// 			x++;
// 		}
// 		y++;
// 	}
// 	game->moves = 0;
// 	game->collects = game->og_collects;
// 	mlx_put_image_to_window(game->mlx, game->window, game->white_panel, 0, 0);
// 	return (0);
// }

void	remove_player(t_game *game)
{
	game->player.tile->type = EMPTY;
	game->player.tile = NULL;
}

/* Input management. Called each time a key is pressed. */
int	input(int key, t_game *game)
{
	t_bool	moved;

	if (key == ESC)
		end_program(game);
	else if (key == RESET)
		return (reset(game));
	if (game->player.tile == NULL)
		return (0);
	if (key == KEY_UP)
		moved = move_to(game, game->player.tile->up);
	else if (key == KEY_DOWN)
		moved = move_to(game, game->player.tile->down);
	else if (key == KEY_LEFT)
		moved = move_to(game, game->player.tile->left);
	else if (key == KEY_RIGHT)
		moved = move_to(game, game->player.tile->right);
	else
		return (0);
	if (moved)
		printf("Moves -> %02d\n", ++game->moves);
	return (1);
}
