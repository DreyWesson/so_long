/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:27:09 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/22 20:07:39 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/* Frees all allocated memory and makes exit(0) */
// int	end_program(t_game *game)
// {
// 	// free_tilemap(game);
// 	free_all(grid, count_row(ptr));
// 	game->tilemap = NULL;
// 	exit(0);
// }

int	start(t_game *game)
{
	// game->collects = 0;
	game->moves = 0;
	game->window = mlx_new_window(game->mlx, IMG_SIZE * game->props.col_nbr, IMG_SIZE * game->props.row_nbr, "Ajala Travel");
	// mlx_hook(game->window, 17, 0, end_program, game);
	// open_images(game);
	return (1);
}

void	handle_map(char **argv, t_game *game)
{
	char		**ptr;
	t_details	props;
	t_cell		**grid;
	t_nodes		**queue;

	queue = (t_nodes **)ft_calloc(sizeof(t_nodes *), 1);
	props = default_details(argv[1]);
	ptr = map_reader(argv[1], props.row_nbr);
	grid = validate_map(ptr, &props, game);
	// grid = create_grid(ptr, &props, game);
	add_head_node(queue, create_node(&grid[props.pos.y][props.pos.x]));
	if (validate_paths(grid, queue) != special_char(ptr))
	{
		free_all(ptr, grid, queue);
		ft_error("Invalid path(s)");
	}
	free_list(queue);
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
