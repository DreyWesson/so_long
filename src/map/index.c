/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:27:09 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/21 15:12:57 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	handle_map(char **argv, t_game *game)
{
	char		**ptr;
	t_details	props;
	t_cell		**grid;
	t_nodes		**queue;

	queue = (t_nodes **)ft_calloc(sizeof(t_nodes *), 1);
	props = default_details(argv[1]);
	ptr = map_reader(argv[1], props.row_nbr);
	validate_map(ptr, &props);
	grid = create_grid(ptr, &props);
	add_head_node(queue, create_node(&grid[props.pos.y][props.pos.x]));
	if (validate_paths(grid, queue) != special_char(ptr))
		ft_error("Invalid path(s)");
	game->props = props;
}
/**
 * // free_all(ptr, grid, queue, &props);
 * @bug -> PROPS[✅], GRID[✅], PTR[✅], QUEUE[✅]
 * possible leakage
*/
