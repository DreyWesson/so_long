/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 09:31:50 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/13 22:15:20 by doduwole         ###   ########.fr       */
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
	READY,
	WAITING,
	VISITED
} e_status;

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
} t_size;

typedef struct s_cell
{
	int val;
	t_coord *pos;
	int x_axis;
	int y_axis;
	// char **adj_list;
	// char *status;
	e_status status;
} t_cell;

typedef struct s_nodes
{
	
} t_nodes;

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
void	validate_map(char **map, int row_nbr, int *col_nbr);
// void	validate_map(char **map, int row_nbr);
int		line_counter(char *file_name);
size_t	ft_strlen_ln(const char *str);
char	**map_reader(char *s, int row_nbr);
/**
 * MAP -> Validator
*/
void	validate_composition(char s, t_quant *quant);
void validate_walls(char *s, int row_nbr, int j, int i);
void	validate_shape(int row_nbr, int *col_nbr, int i, int j);
t_coord	save_start(int x, int y);
void	check_quant(t_quant *quant);
void	default_quant(t_quant *quant);

#endif