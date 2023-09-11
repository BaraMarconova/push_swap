/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <bmarcono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:44:03 by bmarcono          #+#    #+#             */
/*   Updated: 2023/09/11 17:48:38 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both_stacks(t_node *node, t_list0 *A, t_list0 *B)
{
	while (node->ra > 0 && node->rb > 0)
	{
		rr(A, B);
		--(node->ra);
		--(node->rb);
	}
	while (node->rra > 0 && node->rrb > 0)
	{
		rrr(A, B);
		--(node->rra);
		--(node->rrb);
	}
}

void	rotate_stacks(t_node *node, t_list0 *A, t_list0 *B)
{
	while (node->ra > 0)
	{
		ra(A);
		--(node->ra);
	}
	while (node->rb > 0)
	{
		rb(B);
		--(node->rb);
	}
}

void	reverse_rotate_stacks(t_node *node, t_list0 *A, t_list0 *B)
{
	while (node->rra > 0)
	{
		rra(A);
		--(node->rra);
	}
	while (node->rrb > 0)
	{
		rrb(B);
		--(node->rrb);
	}
}
