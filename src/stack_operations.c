/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <bmarcono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:44:39 by bmarcono          #+#    #+#             */
/*   Updated: 2023/09/11 17:48:31 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_list0 *list)
{
	if (list->head == NULL)
		return (0);
	list->head = list->head->next;
	return (0);
}

int	reverse_rotate(t_list0 *list)
{
	if (list->head == NULL)
		return (0);
	list->head = list->head->prev;
	return (0);
}

void	push(t_list0 *list, t_node *node)
{
	list->size += 1;
	if (list->head == NULL)
	{
		list->head = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = list->head;
		node->prev = list->head->prev;
		list->head->prev->next = node;
		list->head->prev = node;
		list->head = list->head->prev;
	}
	list->max_index = get_max(list);
	list->min_index = get_min(list);
}

void	swap(t_list0 *list)
{
	if (list->head == NULL)
		return ;
	list->head->prev->next = list->head->next;
	list->head->next->prev = list->head->prev;
	list->head->prev = list->head->next;
	list->head->next = list->head->next->next;
	list->head->prev->next = list->head;
	list->head->next->prev = list->head;
	list->head = list->head->prev;
}

t_node	*pull(t_list0 *list, t_node *node)
{
	if (list->head == node)
	{
		if (list->size == 0)
		{
			list->head = NULL;
			return (NULL);
		}
		else
		{
			list->head = list->head->next;
		}
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;
	node->next = NULL;
	node->prev = NULL;
	list->max_index = get_max(list);
	list->min_index = get_min(list);
	list->size -= 1;
	return (node);
}
