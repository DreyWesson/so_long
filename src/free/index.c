/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:17:33 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/18 15:21:58 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	free_grid(t_cell **grid, int row_nbr)
{
	int	i;

	i = 0;
	while (i < row_nbr)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	free_list(t_nodes **head_ref)
{
	t_nodes	*tmp;

	if (!head_ref)
		return ;
	while (*head_ref)
	{
		tmp = (*head_ref)->next;
		free(*head_ref);
		*head_ref = tmp;
	}
}

int	count_row(char **grid)
{
	int		y;

	y = 0;
	while (grid[y])
		y++;
	return (y);
}

void	free_all(char **ptr, t_cell **grid, t_nodes **queue, t_details	*props)
{
	free_grid(grid, count_row(ptr));
	ft_free2d(ptr);
	free_list(queue);
	free(props);
}