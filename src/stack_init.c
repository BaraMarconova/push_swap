/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <bmarcono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:44:19 by bmarcono          #+#    #+#             */
/*   Updated: 2023/09/11 17:48:34 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_init(t_list0 **list)
{
	*list = (t_list0 *)malloc(sizeof(t_list0));
	(*list)->size = 0;
	(*list)->groups_count = 0;
	(*list)->max_index = 0;
	(*list)->min_index = 0;
	(*list)->head = NULL;
}

void	reset_rotations(t_node *node)
{
	node->rb = 0;
	node->ra = 0;
	node->rrb = 0;
	node->rra = 0;
}

t_node	*ft_lstnew(int content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->content = content;
	new_node->index = 0;
	new_node->group = 0;
	new_node->rb = 0;
	new_node->ra = 0;
	new_node->rrb = 0;
	new_node->rra = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	clear(t_list0 **list)
{
	while ((*list)->head)
		free(pull(*list, (*list)->head));
	free(*list);
	*list = NULL;
}
