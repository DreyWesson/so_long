/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:27:09 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/27 22:16:37 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/* Frees all allocated memory and makes exit(0) */
int	end_program(t_game *game)
{
	free_grid(game->grid, game->props.row_nbr);
	game->grid = NULL;
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
	game->moves = 0;
	// game->collects = game->props.burger_nbr;
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->wndw_size.x + IMG_SIZE / 2,
			game->wndw_size.y + IMG_SIZE / 2, "Ajala Travel");

	mlx_hook(game->window, 17, 0, end_program, game);
	open_images(game);
	game->white_panel = new_panel(game, new_color(80, 200, 120, 0));
	game->red_panel = new_panel(game, new_color(197, 4, 4, 0));
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
 * remember ANIME_SETUP tiletype, og_type, collects, player
*/
/**
 * // free_all(ptr, grid, queue, &props);
 * @bug -> PROPS[✅], GRID[✅], PTR[✅], QUEUE[✅]
 * possible leakage
*/
