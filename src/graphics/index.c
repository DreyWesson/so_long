/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:13:24 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/29 17:14:31 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	game_init(t_game *game, t_cell	**grid, t_details details)
{
	int	row;
	int	col;

	game->window_size.x = details.col_nbr * IMG_SIZE;
	game->window_size.y = details.row_nbr * IMG_SIZE;
	game->props = details;
	game->moves = 0;
	game->player.tile = &grid[details.pos.y][details.pos.x];
	game->collects = details.burger_nbr;
	game->grid = grid;
	game->mlx = mlx_init();
	col = game->window_size.x + IMG_SIZE / 2;
	row = game->window_size.y + IMG_SIZE / 2;
	game->window = mlx_new_window(game->mlx, col, row, "Ajala Travel");
}
