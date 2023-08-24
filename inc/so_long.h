/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 09:31:50 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/24 18:46:50 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef IMG_SIZE
#  define IMG_SIZE 42
// #  define ESC_KEY 53
// #  define KEY_W 13
// #  define KEY_S 1
// #  define KEY_D 2
// #  define KEY_A 0
# endif

enum	e_status
{
	SPACE = '0',
	BLOCK = '1',
	WAITING = '2',
	VISITED = '3'
};

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
}	t_tiletype;

typedef enum e_compass
{
	UP = 'U',
	DOWN = 'D',
	LEFT = 'L',
	RIGHT = 'R'
}	t_compass;

typedef struct s_quant
{
	int	collectibles;
	int	exit;
	int	player;
}	t_quant;

typedef struct s_axis
{
	int	x;
	int	y;
}	t_axis;

typedef struct s_dir
{
	t_axis		coord;
	t_compass	arrow;
}	t_dir;

typedef struct s_details
{
	int		col_nbr;
	int		row_nbr;
	int		burger_nbr;
	t_axis	pos;
}	t_details;


typedef struct s_cell
{
	char		val;
	int			x_axis;
	int			y_axis;
	char		status;
	t_tiletype	type;
	t_tiletype	og_type;
	t_axis		position;
	struct s_cell	*up;
	struct s_cell	*down;
	struct s_cell	*left;
	struct s_cell	*right;
}	t_cell;

typedef struct s_nodes
{
	t_cell			*cell;
	struct s_nodes	*next;
	struct s_nodes	*prev;
}	t_nodes;

typedef struct s_tile
{
	t_tiletype		type;
	t_tiletype		og_type;
	t_axis			position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef struct s_player
{
	t_cell	*tile;
	void	*current_img;
	int		framecount;
	int		idle_frames;
	void	*idle_img_0;
	void	*idle_img_1;
	int		action_frames;
	void	*action_img;
}	t_player;

typedef struct s_wall_img
{
	void	*block;
	void	*up_left;
	void	*up;
	void	*up_right;
	void	*right;
	void	*down_right;
	void	*down;
	void	*down_left;
	void	*left;
}	t_wall_img;

typedef struct s_effect
{
	void		*img;
	t_axis		pos;
	int			frames;
	int			counter;
}	t_effect;

typedef struct s_coll_img
{
	void	*current_img;
	int		anim_frames;
	void	*img_0;
	void	*img_1;
}	t_collect_img;

enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 15,
	ESC = 53
};

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_axis			wndw_size;
	t_player		player;
	int				collects;
	int				moves;
	t_tile			**tilemap;
	t_cell			**grid;
	int				og_collects;
	t_details		props;

	t_axis			img_size;
	t_wall_img		wall_imgs;
	t_collect_img	collects_imgs;
	void			*door_open_img;
	void			*door_close_img;
	t_effect		effect;
	void			*red_panel;
	void			*white_panel;
}	t_game;

/**
 * UTILS FUNCTION
*/
int			ft_error(char *message);
void		ft_warning(char *message);
int			ft_trim(char const *s1, char const *set);
int			handle_validation(int argc, char **argv, t_game *game);
/**
 * MAP -> Reader
*/
void		handle_map(char **argv, t_game *game);
int			validate_map(char **map, t_details *details,
				t_game *game, t_nodes **queue);
int			line_counter(char *file_name);
size_t		ft_strlen_ln(const char *str);
char		**map_reader(char *s, int row_nbr);
/**
 * MAP -> Validator
*/
int			validate_composition(char s, t_quant *quant);
int			validate_walls(char *s, int row_nbr, int j, int i);
int			validate_shape(t_details *details, int i, int j);
void		save_start(int x, int y, t_details *details);
void		check_quant(t_quant *quant, t_details *details);
void		default_quant(t_quant *quant);
t_cell		create_cell(char s, int x, int y);
t_details	default_details(char *ptr);
void		print_grid(t_cell **grid, t_details details);
void print_adjacent(t_details details, t_cell **grid);
t_details	set_tmp(t_nodes **queue, t_details *details);
int			special_char(char **map);
t_cell		**create_grid(char **map, t_details *details, t_game *game);
void		handle_adjacency(t_cell **grid, t_nodes **queue);
int			validate_paths(t_cell **grid, t_nodes **queue, t_details details);
t_cell		*adjacency_math(t_cell **grid,
				t_nodes **queue, int y, int x);
/**
 * QUEUE
*/
void		add_head_node(t_nodes **old, t_nodes *new);
void		print_node(t_nodes *head, int col_nbr);
void		add_tail_node(t_nodes **old, t_nodes *new);
void		del_node(t_nodes **head);
t_nodes		*last_node(t_nodes *head);
t_nodes		*create_node(t_cell *cell);
/**
 * FREE
*/
int			count_row(char **grid);
void		free_list(t_nodes **head_ref);
void		free_grid(t_cell **grid, int row_nbr);
void		free_all(char **ptr, t_cell **grid, t_nodes	**queue);





int			input(int key, t_game *game);
void		remove_player(t_game *game);
int			reset(t_game *game);
int			update(t_game *game);
void		render(t_game game);



t_bool		draw_corner(t_tile tile, t_game game, t_axis pos);
t_bool		draw_sides(t_tile tile, t_game game, t_axis pos);
void		draw_wall(t_tile tile, t_game game, t_axis pos);
void		effect_anim(t_effect *effect, t_axis pos);
void		action_anim(t_player *player);
t_bool		move_to(t_game *game, t_cell *tile);
int			end_program(t_game *game);
void		open_images(t_game *game);

#endif