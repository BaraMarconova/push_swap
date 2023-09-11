/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <bmarcono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:38:08 by bmarcono          #+#    #+#             */
/*   Updated: 2023/09/11 17:48:52 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_group(t_list0 *list, int value, int group, int index)
{
	t_node	*tmp;

	tmp = list->head;
	while (tmp->next != list->head)
	{
		if (tmp->content == value)
		{
			tmp->group = group;
			tmp->index = index + 1;
		}
		tmp = tmp->next;
	}
	if (tmp->content == value)
	{
		tmp->group = group;
		tmp->index = index + 1;
	}
}

int	*array_from_list_conv(t_list0 *list)
{
	int		*array_from_list;
	int		i;
	t_node	*tmp;

	array_from_list = (int *)malloc(list->size * sizeof(int));
	if (!array_from_list)
		return (NULL);
	i = 0;
	tmp = list->head;
	while (i < list->size)
	{
		array_from_list[i] = tmp->content;
		tmp = tmp->next;
		++i;
	}
	return (array_from_list);
}

void	group_builder(t_list0 *list)
{
	int		*sorted_list;
	int		i;
	int		j;
	int		group;

	sorted_list = array_from_list_conv(list);
	ft_sort_int_tab(sorted_list, list->size);
	i = 0;
	group = 0;
	while (i < list->size)
	{
		j = 0;
		while (j < (list->size + list->groups_count - 1) / list->groups_count \
				&& i < list->size)
		{
			set_group(list, sorted_list[i], group, i);
			++i;
			++j;
		}
		++group;
	}
	free(sorted_list);
	list->max_index = get_max(list);
	list->min_index = get_min(list);
}
