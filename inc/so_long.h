/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 09:31:50 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/20 20:47:47 by doduwole         ###   ########.fr       */
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

enum	e_space_type
{
	EMPTY,
	COLLECTIBLES,
	EXIT
};

enum	e_status
{
	SPACE = '0',
	WALL = '1',
	WAITING = '2',
	VISITED = '3'
};

enum e_move
{
	BWD = -1,
	FWD = 1,
};

typedef struct s_quant
{
	int	collectibles;
	int	exit;
	int	player;
}	t_quant;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_details
{
	int		col_nbr;
	int		row_nbr;
	t_coord	pos;
}	t_details;

typedef struct s_cell
{
	int			val;
	int			x_axis;
	int			y_axis;
	char		status;
}	t_cell;

typedef struct s_nodes
{
	t_cell			*cell;
	struct s_nodes	*next;
	struct s_nodes	*prev;
}	t_nodes;

/**
 * UTILS FUNCTION
*/
int			ft_error(char *message);
void		ft_warning(char *message);
int			ft_trim(char const *s1, char const *set);
int			handle_validation(int argc, char **argv);
/**
 * MAP -> Reader
*/
void		handle_map(char **argv);
void		validate_map(char **map, t_details *details);
int			line_counter(char *file_name);
size_t		ft_strlen_ln(const char *str);
char		**map_reader(char *s, int row_nbr);
/**
 * MAP -> Validator
*/
void		validate_composition(char s, t_quant *quant);
void		validate_walls(char *s, int row_nbr, int j, int i);
void		validate_shape(t_details *details, int i, int j);
t_coord		save_start(int x, int y);
void		check_quant(t_quant *quant);
void		default_quant(t_quant *quant);
t_cell		create_cell(char s, int x, int y);
t_details	*default_details(char *ptr);
void		print_grid(t_cell **grid, t_details details);
t_details	set_tmp(t_nodes **queue, t_details *details);
int			special_char(char **map);
t_cell		**create_grid(char **map, t_details *details);
void		handle_adjacency(t_cell **grid, t_nodes **queue);
int			validate_paths(t_cell **grid, t_nodes **queue);
void		adjacency_math(t_cell **grid, t_nodes **queue, int y, int x);
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
void		free_all(char **ptr, t_cell **grid, t_nodes	**queue,
				t_details	*props);

#endif