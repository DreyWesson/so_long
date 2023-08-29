/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 06:28:34 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/29 15:14:53 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

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

t_cell	**create_grid(char **map, t_details *details)
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
	return (grid);
}

t_cell	*adjacency_math(t_cell **grid, t_nodes **queue, int y, int x)
{
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

int	special_char(char **map)
{
	int	y_axis;
	int	x_axis;
	int	sum;

	y_axis = 0;
	sum = 0;
	while (map[y_axis])
	{
		x_axis = 0;
		while (map[y_axis][x_axis])
		{
			if (map[y_axis][x_axis] != BLOCK && map[y_axis][x_axis] != SPACE)
				sum++;
			x_axis++;
		}
		y_axis++;
	}
	return (sum);
}
