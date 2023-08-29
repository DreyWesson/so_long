/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 07:30:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/29 13:57:05 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

/* Frees all allocated memory and makes exit(0) */
int	end_program(t_game *game)
{
	free_grid(game->grid, game->props.row_nbr);
	game->grid = NULL;
	exit(0);
}

// /* Returns the game to its original state */
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
			game->grid[y][x].type = game->grid[y][x].mem_type;
			if (game->grid[y][x].type == PLAYER)
				game->player.tile = &game->grid[y][x];
			x++;
		}
		y++;
	}
	game->moves = 0;
	game->collects = game->props.burger_nbr;
	// mlx_put_image_to_window(game->mlx, game->window, game->green_panel, 0, 0);
	return (0);
}

void	remove_player(t_game *game)
{
	game->player.tile->type = EMPTY;
	game->player.tile = NULL;
}


