/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <bmarcono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:44:56 by bmarcono          #+#    #+#             */
/*   Updated: 2023/09/11 17:48:27 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list0 *list)
{
	int		i;
	int		min;
	t_node	*cur;

	i = 0;
	if (list->size == 0 || list == NULL)
		return (-1);
	cur = list->head;
	min = cur->index;
	while (i < list->size)
	{
		if (cur->index < min)
			min = cur->index;
		cur = cur->next;
		++i;
	}
	return (min);
}

int	get_max(t_list0 *list)
{
	t_node	*current;
	int		max;
	int		i;

	max = -1;
	i = 0;
	if (list->size == 0)
		return (-1);
	current = list->head;
	while (i < list->size)
	{
		if (current->index > max)
		{
			max = current->index;
		}
		current = current->next;
		++i;
	}
	return (max);
}

int	get_next_max(t_list0 *list, int value)
{
	int		i;
	int		next_max;
	t_node	*current;

	i = 0;
	next_max = list->max_index;
	current = list->head;
	while (i < list->size)
	{
		if (current->index > value && current->index < next_max)
			next_max = current->index;
		current = current->next;
		++i;
	}
	return (next_max);
}

int	is_sorted(t_list0 *list)
{
	int		i;
	t_node	*current;

	i = 0;
	current = list->head;
	while (i < list->size - 1)
	{
		if (current->next->content < current->content)
			return (0);
		current = current->next;
		++i;
	}
	return (1);
}
