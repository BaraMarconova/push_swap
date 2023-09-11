/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <bmarcono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:43:54 by bmarcono          #+#    #+#             */
/*   Updated: 2023/09/11 17:48:41 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list0 *A, t_list0 *B)
{
	if (A->size >= 300)
	{
		A->groups_count = 7;
		sort_large(A, B);
	}
	else if (A->size >= 80)
	{
		A->groups_count = 5;
		sort_large(A, B);
	}
	else if (A->size > 5)
	{
		A->groups_count = 3;
		sort_large(A, B);
	}
	else if (A->size > 3 && A->size <= 5)
	{
		A->groups_count = 1;
		sort_five(A, B);
	}
	else if (A->size <= 3)
		sort_three(A);
}

int	main(int argc, char *argv[])
{
	t_list0	*stack_a;
	t_list0	*stack_b;

	ft_list_init(&stack_a);
	ft_list_init(&stack_b);
	if (argc < 2)
	{
		ft_printf("ERROR: No input provided.\n");
		return (1);
	}
	if (fill_list(stack_a, argc, argv) == -1)
		return (1);
	if (is_sorted(stack_a))
	{
		ft_printf("\n");
		return (0);
	}
	sort (stack_a, stack_b);
	clear(&stack_a);
	clear(&stack_b);
	return (0);
}
