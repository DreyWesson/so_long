/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:05:51 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/01 16:25:51 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (!handle_validation(argc, argv, &game))
		exit(1);
	mlx_hook(game.window, 2, 0, input, (void *)&game);
	mlx_hook(game.window, 17, 0, end_program, &game);
	mlx_loop_hook(game.mlx, update, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
