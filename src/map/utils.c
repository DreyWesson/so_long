/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 06:25:55 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/30 09:26:27 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	is_valid(char *str)
{
	char	*s;
	int		len;
	int		res;

	res = 0;
	len = ft_trim(str, "./");
	while (str[len])
	{
		if (str[len] == '.')
		{
			s = ft_substr(&str[len], 0, 4);
			if (ft_strncmp(s, ".ber", 4) == 0 && !str[len + 4])
				res = 1;
			else
				break ;
		}
		len++;
	}
	if (len == 4)
	{
		ft_error("File name doesn't exist");
		exit(0);
	}
	free(s);
	return (res);
}

int	valid_move(t_nodes **queue)
{
	if (((*queue)->cell->val != SPACE && (*queue)->cell->val != BLOCK))
		return (1);
	return (0);
}

int	check_paths(t_cell **grid, t_nodes **queue, t_details details)
{
	int	memo;

	if (grid[details.pos.y][details.pos.x].val == 'P')
		add_head_node(queue, create_node(&grid[details.pos.y][details.pos.x]));
	handle_adjacency(grid, queue);
	memo = valid_move(queue);
	del_node(queue);
	if (!*queue)
		return (memo);
	details.pos.x = (*queue)->cell->x_axis;
	details.pos.y = (*queue)->cell->y_axis;
	return (check_paths(grid, queue, details) + memo);
}

t_cell	**validate_paths(t_cell **grid, t_nodes **queue,
	t_details details, char **map)
{
	int	collectibles;

	collectibles = special_char(map);
	if (check_paths(grid, queue, details) != collectibles)
	{
		ft_error("Invalid path(s)");
		free_grid(grid, details.row_nbr, 1);
		// return (NULL);
	}
	return (grid);
}
