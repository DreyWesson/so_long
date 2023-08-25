/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 06:28:34 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/25 06:29:26 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

void	game_init(t_game *game, t_cell	**grid, t_details details)
{
	game->wndw_size.x = details.pos.x * IMG_SIZE;
	game->wndw_size.y = details.pos.y * IMG_SIZE;
	game->props = details;
	game->player.tile = &grid[details.pos.y][details.pos.x];
	game->collects = details.burger_nbr;
	game->og_collects = details.burger_nbr;
	game->grid = grid;

}

t_cell	**create_grid(char **map, t_details *details, t_game *game)
{
	int		x;
	int		y;
	t_cell	**grid;

	y = 0;
	grid = (t_cell **)ft_calloc(sizeof(t_cell *), details->row_nbr);
	while (y < details->row_nbr)
	{
		x = 0;
		grid[y] = (t_cell *)ft_calloc(sizeof(t_cell), details->col_nbr);
		while (x < details->col_nbr)
		{
			grid[y][x] = create_cell(map[y][x], x, y);
			x++;
		}
		y++;
	}
	grid[details->pos.y][details->pos.x].status = WAITING;
	game_init(game, grid, *details);
	return (grid);
}

t_cell	*adjacency_math(t_cell **grid, t_nodes **queue, int y, int x)
{
	// if it's not equal to block only is enough
	if (grid[y][x].status == SPACE && grid[y][x].val != BLOCK)
	{
		add_head_node(queue, create_node(&grid[y][x]));
		grid[y][x].status = WAITING;
	}
	return (&grid[y][x]);
}

void	handle_adjacency(t_cell **grid, t_nodes **queue)
{
	int		x;
	int		y;

	x = (*queue)->cell->x_axis;
	y = (*queue)->cell->y_axis;
	grid[y][x].up = adjacency_math(grid, queue, y - 1, x);
	grid[y][x].down = adjacency_math(grid, queue, y + 1, x);
	grid[y][x].left = adjacency_math(grid, queue, y, x - 1);
	grid[y][x].right = adjacency_math(grid, queue, y, x + 1);
	(*queue)->cell->status = VISITED;
}
