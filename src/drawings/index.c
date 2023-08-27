/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 07:28:12 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/27 09:55:02 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

t_bool	draw_corner(t_cell cell, t_game game, t_axis pos)
{
	if (cell.position.x == 0
		&& cell.position.y == 0)
		{
			mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.up_left, pos.x, pos.y);
		}
	else if (cell.position.x == 0
		&& cell.position.y == game.wndw_size.y - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.down_left, pos.x, pos.y);
	else if (cell.position.x == game.wndw_size.x - IMG_SIZE
		&& cell.position.y == 0)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.up_right, pos.x, pos.y);
	else if (cell.position.x == game.wndw_size.x - IMG_SIZE
		&& cell.position.y == game.wndw_size.y - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.down_right, pos.x, pos.y);
	else
		return (FALSE);
	return (TRUE);
}

t_bool	draw_sides(t_cell cell, t_game game, t_axis pos)
{
	if (cell.position.x == 0)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.left, pos.x, pos.y);
	else if (cell.position.x == game.wndw_size.x - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.right, pos.x, pos.y);
	else if (cell.position.y == 0)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.up, pos.x, pos.y);
	else if (cell.position.y == game.wndw_size.y - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.down, pos.x, pos.y);
	else
		return (FALSE);
	return (TRUE);
}

// /* Draws the corresponding sprite for the wall at <pos> */
void	draw_wall(t_cell cell, t_game game, t_axis pos)
{
	if (draw_corner(cell, game, pos))
		return ;
	else if (draw_sides(cell, game, pos))
		return ;
	mlx_put_image_to_window(game.mlx, game.window,
		game.wall_imgs.block, pos.x, pos.y);
}

// /* Draws the corresponding image of the tile type */
static void	draw_image(t_cell cell, t_game game, t_axis pos)
{
	if (cell.type == WALL){
		draw_wall(cell, game, pos);
		// printf("2. debug\n");
	}
	else if (cell.type == EXIT)
	{
		// printf("2. debug\n");
		if (game.collects != 0)
			mlx_put_image_to_window(game.mlx, game.window,
				game.door_open_img, pos.x, pos.y);
		if (game.collects == 0)
			mlx_put_image_to_window(game.mlx, game.window,
				game.door_close_img, pos.x, pos.y);
	}
	else if (cell.type == COLLECTABLE)
	{
		// printf("3. debug\n");
		mlx_put_image_to_window(game.mlx, game.window,
			game.collects_imgs.current_img, pos.x, pos.y);

	}
	else if (cell.type == PLAYER)
	{
		// printf("4. debug\n");
		mlx_put_image_to_window(game.mlx, game.window,
			game.player.current_img, pos.x, pos.y);

	}
}

// /* If the effect counter is less than its animation frames, draws it */
// static void	draw_effect(t_game game)
// {
// 	if (game.effect.counter < game.effect.frames)
// 		mlx_put_image_to_window(game.mlx, game.window,
// 			game.effect.img,
// 			game.effect.pos.x, game.effect.pos.y);
// }

// /* Writes the number of moves on the window,
// changing its color if the game is completed  */

// static void	draw_text(t_game game)
// {
// 	char	*str;

// 	str = ft_itoa(game.moves);
// 	if (game.collects >= 0)
// 		mlx_string_put(game.mlx, game.window,
// 			game.wndw_size.x - IMG_SIZE / 2.3,
// 			IMG_SIZE - IMG_SIZE / 1.5,
// 			-1, str);
// 	else
// 		mlx_string_put(game.mlx, game.window,
// 			game.wndw_size.x - IMG_SIZE / 2.3,
// 			IMG_SIZE - IMG_SIZE / 1.5,
// 			15921152, str);
// 	free(str);
// }

// /* Puts the tile map on the window */
// void	render(t_game game)
// {
// 	t_cell	tile;
// 	int		x;
// 	int		y;
// 	mlx_clear_window(game.mlx, game.window);
// 	y = 0;
// 	while (game.grid[y] != NULL)
// 	{
// 		x = 0;
// 		while (game.grid[y][x].type != 0)
// 		{
// 			tile = game.grid[y][x];
// 			draw_image(tile, game, tile.position);
// 			// draw_effect(game);
// 			x++;
// 		}
// 		y++;
// 	}
// 	// draw_text(game);
// }

void	render(t_game game)
{
	int		x;
	int		y;

	y = 0;

	mlx_clear_window(game.mlx, game.window);
	while (y < game.props.row_nbr)
	{
		x = 0;
		while (x < game.props.col_nbr)
		{
			draw_image(game.grid[y][x], game, game.grid[y][x].position);
			// draw_effect(game);
			x++;
		}
		y++;
	}
	// draw_text(game);
}