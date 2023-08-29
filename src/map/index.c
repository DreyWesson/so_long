/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:27:09 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/29 02:10:16 by doduwole         ###   ########.fr       */
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
	int size;

	size = game->wndw_size.x + IMG_SIZE / 2;
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, size, size, "Ajala Travel");
	mlx_hook(game->window, 17, 0, end_program, game);
	open_images(game);
	game->green_panel = new_panel(game, new_color(80, 200, 120, 0));
	game->red_panel = new_panel(game, new_color(197, 4, 4, 0));
}

void	handle_map(char **argv, t_game *game)
{
	char		**ptr;
	t_details	props;
	t_nodes		*queue;
	t_cell		**grid;

	props = default_details(argv[1]);
	ptr = map_reader(argv[1], props.row_nbr);
	grid = validate_map(ptr, &props, &queue);
	free(queue);
	ft_free2d(ptr);
	if (!grid)
	{
		free(grid);
		exit(1);
	}
	game_init(game, grid, props);
	anim_setup(game);
	start(game);
}
