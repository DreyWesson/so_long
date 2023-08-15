/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 09:31:50 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/15 19:40:12 by doduwole         ###   ########.fr       */
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

typedef enum	
{
	EMPTY,
	COLLECTIBLES,
	EXIT
} e_space_type;

typedef enum	
{
	RESTING = 1,
	WAITING = 2,
	VISITED = 3
} e_status;

typedef enum
{
	BWD = -1,
	FWD = 1,
} e_move;

typedef struct s_quant
{
	int collectibles;
	int exit;
	int player;
} t_quant;

typedef struct s_coord
{
	int x;
	int y;
} t_coord;

typedef struct s_size
{
	int col_nbr;
	int row_nbr;
	t_coord start_pos;
} t_size;

typedef struct s_cell
{
	int val;
	int x_axis;
	int y_axis;
	// char **adj_list;
	// char *status;
	e_status status;
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
int		ft_error(char *message);
void	ft_warning(char *message);
int		ft_trim(char const *s1, char const *set);
int		handle_validation(int argc, char **argv);
/**
 * MAP -> Reader
*/
void 	handle_map(char **argv);
void	validate_map(char **map, t_size *size);
// void	validate_map(char **map, int row_nbr);
int		line_counter(char *file_name);
size_t	ft_strlen_ln(const char *str);
char	**map_reader(char *s, int row_nbr);
/**
 * MAP -> Validator
*/
void	validate_composition(char s, t_quant *quant);
void validate_walls(char *s, int row_nbr, int j, int i);
void	validate_shape(t_size *size, int i, int j);
t_coord	save_start(int x, int y);
void	check_quant(t_quant *quant);
void	default_quant(t_quant *quant);
/**
 * QUEUE
*/
void	add_head_node(t_nodes **old, t_nodes *new);
void	print_node(t_nodes *head, int col_nbr);
void	add_tail_node(t_nodes **old, t_nodes *new);
void	del_node(t_nodes **head);
t_nodes	*last_node(t_nodes *head);
t_nodes	*create_node(t_cell *cell);

#endif