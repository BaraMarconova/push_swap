/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_container_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <bmarcono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:58:52 by bmarcono          #+#    #+#             */
/*   Updated: 2023/09/11 17:48:04 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list0 *A)
{
	swap(A);
	ft_printf("sa\n");
}

void	rra(t_list0 *A)
{
	reverse_rotate(A);
	ft_printf("rra\n");
}

void	rrb(t_list0 *B)
{
	reverse_rotate(B);
	ft_printf("rrb\n");
}

void	rrr(t_list0 *A, t_list0 *B)
{
	reverse_rotate(A);
	reverse_rotate(B);
	ft_printf("rrr\n");
}
