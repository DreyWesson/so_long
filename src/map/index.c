/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:27:09 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/29 07:41:56 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/* Sets the frames of all animatios */
static void	anim_setup(t_game *game)
{
	game->player.idle_frames = 17;
	game->player.action_frames = 10;
	game->collects_imgs.anim_frames = 25;
	game->effect.frames = 7;
}

void	start(t_game *game, t_cell **grid, t_details props)
{
	game_init(game, grid, props);
	anim_setup(game);
	open_images(game);
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
	start(game, grid, props);
}

int	handle_validation(int argc, char **argv, t_game *game)
{
	if (argc == 1)
		return (ft_error("Too few argument"));
	if (argc > 2)
		ft_warning("Processing the first argument only");
	if (!is_valid(argv[1]))
		return (ft_error("Expecting a .ber file"));
	handle_map(argv, game);
	return (1);
}
