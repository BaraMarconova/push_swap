/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <bmarcono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:44:10 by bmarcono          #+#    #+#             */
/*   Updated: 2023/09/11 19:03:02 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_list0 *A)
{
	if (A->head->content > A->head->next->content && \
			A->head->content > A->head->next->next->content)
	{
		rotate(A);
		ft_printf("ra\n");
	}
	else if (A->head->next->content > A->head->content && \
			A->head->next->content > A->head->next->next->content)
	{
		reverse_rotate(A);
		ft_printf("rra\n");
	}
	if (A->head->content > A->head->next->content)
	{
		swap(A);
		ft_printf("sa\n");
	}
	return (0);
}

int	sort_five(t_list0 *A, t_list0 *B)
{
	group_builder(A);
	presort_five(A, B);
	sort_three(A);
	while (B->size != 0)
	{
		if (B->head->index > A->max_index)
		{
			pa(A, B);
			ra(A);
		}
		else
		{
			pa(A, B);
			if (A->head->index > A->head->next->index)
				sa(A);
		}
	}
	return (0);
}

void	doit(t_node *node, t_list0 *A, t_list0 *B)
{
	if (node == NULL)
		return ;
	rotate_both_stacks(node, A, B);
	rotate_stacks(node, A, B);
	reverse_rotate_stacks(node, A, B);
	pa(A, B);
}

void	final_rotation(t_list0 *list)
{
	while (list->head->index != list->min_index)
		rra(list);
}

void	sort_large(t_list0 *A, t_list0 *B)
{
	t_node	*min;
	int		group;

	min = NULL;
	group = A->groups_count - 1;
	group_builder(A);
	presort(A, B);
	sort_three(A);
	while (B->size != 0)
	{
		rotation_calculation(A, B);
		min = get_min_cost(B, group);
		doit(min, A, B);
		if (!if_group(B, group))
			--group;
	}
	final_rotation(A);
}
