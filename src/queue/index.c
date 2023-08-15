/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:36:50 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/15 13:38:01 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

t_nodes *create_node(t_cell *cell)
{
	t_nodes *node;

	node = (t_nodes *)malloc(sizeof(t_nodes));
	if (!node)
		return (NULL);
	node->cell = cell;
	// node->pos = pos;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_nodes *last_node(t_nodes *head)
{
	t_nodes *tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void del_node(t_nodes **head)
{
	t_nodes *tmp;

	tmp = *head;
	if (!(*head)->next)
	{
		*head = NULL;
		return ;
	}
	/**
	 * @bug -> previous head
	 * possible leakage
	*/
	*head = tmp->next;
}

void add_tail_node(t_nodes **old, t_nodes *new)
{
	new->next = *old;
	if (*old)
		(*old)->prev = new;
	*old = new;
}

void print_node(t_nodes *head, int col_nbr)
{
	t_nodes *tmp;

	tmp = head;
	while (tmp)
	{
		// printf("%s -> %d - %d\n", tmp->pos, tmp->value, tmp->status);
		printf(
			"value: %c, x: %d, y: %d, status: %d\n",
			tmp->cell->val,
			tmp->cell->x_axis,
			tmp->cell->y_axis,
			tmp->cell->status
			);

		if (col_nbr - 1 == tmp->cell->x_axis)
			printf("\n");

		tmp = tmp->next;
	}
}

void add_head_node(t_nodes **old, t_nodes *new)
{
	t_nodes *tmp;

	if (*old == NULL)
	{
		*old = new;
		return ;
	}
	tmp = last_node(*old);
	new->prev = tmp;
	tmp->next = new;
}

/**
 * @brief list functions
 * add current pos to queue
 * pop current pos to visited list
 * add adjacent pos to queue
 * repeat
*/

// int main()
// {
// 	t_node *queue;
// 	int vals[4] = {1,2,3,4};
// 	int grid[4][4] = {
// 		1,2,3,4,
// 		5,6,7,8,
// 		9,10,11,12,
// 		13,14,15,16,
// 	};
// 	int i = 0;
// 	queue = (t_node *)malloc(sizeof(t_node));
// 	queue = NULL;
// 	while (i < 4)
// 	{
// 		add_head(&queue, create(vals[i]));
// 		i++;
// 	}
// 	add_tail(&queue, create(9));
// 	print(queue);
// 	return (0);
// }
