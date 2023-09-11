/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_container.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <bmarcono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:43:38 by bmarcono          #+#    #+#             */
/*   Updated: 2023/09/11 17:48:15 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list0 *A, t_list0 *B)
{
	push(B, pull(A, A->head));
	ft_printf("pb\n");
}

void	pa(t_list0 *A, t_list0 *B)
{
	push(A, pull(B, B->head));
	ft_printf("pa\n");
}

void	ra(t_list0 *A)
{
	rotate(A);
	ft_printf("ra\n");
}

void	rb(t_list0 *B)
{
	rotate(B);
	ft_printf("rb\n");
}

void	rr(t_list0 *A, t_list0 *B)
{
	rotate(A);
	rotate(B);
	ft_printf("rr\n");
}
