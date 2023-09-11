/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <bmarcono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:43:47 by bmarcono          #+#    #+#             */
/*   Updated: 2023/09/11 19:01:47 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_group(t_list0 *list, int group)
{
	t_node	*tmp;
	int		i;

	tmp = list->head;
	i = 0;
	if (list->size == 0)
		return (0);
	while (i < list->size)
	{
		if (tmp->group == group)
			return (1);
		tmp = tmp->next;
		++i;
	}
	return (0);
}

void	presort(t_list0	*A, t_list0 *B)
{
	int	group;

	group = 0;
	while (group != A->groups_count - 1)
	{
		if (!if_group(A, group))
		{
			++group;
			continue ;
		}
		if (A->head->group == group || (A->head->group == group + 1 \
		&& A->head->group != A->groups_count - 1))
			pb(A, B);
		if (B->size != 0 && A->size != 0 && A->head->group > group + 1 \
		&& B->size > 1 && (B->head->group % 2 == 0))
			rr(A, B);
		else if (B->size > 1 && B->head->group % 2 == 0)
			rb(B);
		else
			ra(A);
	}
	last_group_push(A, B);
}

void	last_group_push(t_list0 *A, t_list0 *B)
{
	while (A->size > 3)
	{
		if (A->head->index > A->size + B->size - 3)
			ra(A);
		else
			pb(A, B);
	}
}

void	presort_five(t_list0	*A, t_list0 *B)
{
	while (A->size > 3 && !is_sorted(A))
	{
		if (A->head->index == A->min_index || \
			(A->head->index == A->min_index + 1 \
			&& A->head->index != 3) || \
			A->head->index == A->size + B->size)
			pb(A, B);
		else if (A->head->prev->index == A->min_index \
				|| (A->head->prev->index == A->min_index + 1 && \
				A->head->prev->index != 3) || \
				A->head->prev->index == A->size + B->size)
			rra(A);
		else
			ra(A);
	}
}
