/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:27:09 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/25 06:26:07 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/* Frees all allocated memory and makes exit(0) */
int	end_program(t_game *game)
{
	free_grid(game->grid, game->props.row_nbr);
	exit(0);
}



/* Sets the frames of all animatios */
static void	anim_setup(t_game *game)
{
	game->player.idle_frames = 17;
	game->player.action_frames = 10;
	game->collects_imgs.anim_frames = 25;
	game->effect.frames = 7;
}

void	start(t_game *game)
{
	game->collects = 0;
	game->moves = 0;
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, IMG_SIZE * game->props.col_nbr, IMG_SIZE * game->props.row_nbr, "Ajala Travel");

	mlx_hook(game->window, 17, 0, end_program, game);
	open_images(game);
	// return (1);
}

void	handle_map(char **argv, t_game *game)
{
	char		**ptr;
	t_details	props;
	t_nodes		**queue;

	queue = (t_nodes **)ft_calloc(sizeof(t_nodes *), 1);
	props = default_details(argv[1]);
	ptr = map_reader(argv[1], props.row_nbr);
	validate_map(ptr, &props, game, queue);
	free_list(queue);
	ft_free2d(ptr);
	anim_setup(game);
	start(game);

}
/// @brief
/**
 * remember ANIME_SETUP tiletype, og_type, og_collects, collects, player
*/
/**
 * // free_all(ptr, grid, queue, &props);
 * @bug -> PROPS[✅], GRID[✅], PTR[✅], QUEUE[✅]
 * possible leakage
*/
