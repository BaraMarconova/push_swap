/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <bmarcono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:41:57 by bmarcono          #+#    #+#             */
/*   Updated: 2023/09/11 17:48:21 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_min_cost(t_list0 *list, int group)
{
	int		i;
	t_node	*cur;
	t_node	*min_cost;

	i = 0;
	cur = list->head;
	min_cost = cur;
	if (list->size == 0 || list == NULL)
		return (NULL);
	min_cost = get_group_first(list, group);
	while (i < list->size)
	{
		++i;
		if (cur->cost <= min_cost->cost && cur->index > min_cost->index \
		&& cur->group == group)
			min_cost = cur;
		cur = cur->next;
	}
	return (min_cost);
}

t_node	*get_group_first(t_list0 *list, int group)
{
	t_node	*cur;
	int		i;

	i = 0;
	cur = list->head;
	while (i < list->size)
	{
		if (cur->group == group)
			return (cur);
		cur = cur->next;
		++i;
	}
	return (cur);
}

int	get_rotations(t_list0 *A, int value)
{
	int		rotations;
	t_node	*current;

	rotations = 0;
	current = A->head;
	while (current->index != value)
	{
		current = current->next;
		rotations++;
	}
	return (rotations);
}

void	cost_calculation(t_node *node, int size_A, int size_B)
{
	if (node->ra > size_A / 2)
	{
		node->rra = size_A - node->ra;
		node->ra = 0;
	}
	if (node->rb > size_B / 2)
	{
		node->rrb = size_B - node->rb;
		node->rb = 0;
	}
	if (node->ra == 0 && node->rb == 0)
		node->cost = max(node->rra, node->rrb);
	else if (node->ra > 0 && node->rb > 0)
		node->cost = max(node->ra, node->rb);
	else
		node->cost = node->ra + node->rb + node->rra + node->rrb;
	if (node->ra == 0 && node->rb == 0)
		node->cost = max(node->rra, node->rrb);
	else if (node->ra > 0 && node->rb > 0)
		node->cost = max(node->ra, node->rb);
	else
		node->cost = node->ra + node->rb + node->rra + node->rrb;
}

void	rotation_calculation(t_list0 *A, t_list0 *B)
{
	t_node	*cur_b;
	int		i;

	cur_b = B->head;
	i = 0;
	while (i < B->size)
	{
		reset_rotations(cur_b);
		cur_b->rb = i;
		if (cur_b->index < A->min_index)
			cur_b->ra = get_rotations(A, A->min_index);
		else
			cur_b->ra = get_rotations(A, get_next_max(A, cur_b->index));
		cost_calculation(cur_b, A->size, B->size);
		++i;
		cur_b = cur_b->next;
	}
}
