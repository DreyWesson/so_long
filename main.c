/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:05:51 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/21 15:14:23 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

void init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, SIZE * game->props.col_nbr,
			SIZE * game->props.row_nbr, "The Journey of Nas");
}

int	main(int argc, char **argv)
{
	t_game	game;

	handle_validation(argc, argv, &game);

	// printf("X: %d, Y: %d, Col: %d, Row: %d\n", game.details.pos.x, game.details.pos.y,game.details.col_nbr,game.details.row_nbr);
	return (0);
}
