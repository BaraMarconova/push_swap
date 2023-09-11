/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <bmarcono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:46:10 by bmarcono          #+#    #+#             */
/*   Updated: 2023/09/11 19:05:32 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_node
{
	int				content;
	int				group;
	int				index;
	int				cost;
	int				rrb;
	int				rra;
	int				ra;
	int				rb;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list0
{
	t_node	*head;
	int		max_index;
	int		min_index;
	int		groups_count;
	int		size;
}	t_list0;

void	ft_list_init(t_list0 **list);
t_node	*ft_lstnew(int content);

void	rrr(t_list0 *A, t_list0 *B);
void	rra(t_list0 *A);
void	rrb(t_list0 *B);
void	pb(t_list0 *A, t_list0 *B);
void	pa(t_list0 *A, t_list0 *B);
void	ra(t_list0 *A);
void	rb(t_list0 *B);
void	rr(t_list0 *A, t_list0 *B);

void	sa(t_list0 *A);

void	rotate_both_stacks(t_node *node, t_list0 *A, t_list0 *B);
void	rotate_stacks(t_node *node, t_list0 *A, t_list0 *B);
void	reverse_rotate_stacks(t_node *node, t_list0 *A, t_list0 *B);

void	insert_node(t_list0 *list, int content);
int		check_dublicates(t_list0 *list, int content);
int		is_number(char *str);
int		validate_content(t_list0 *list, char *content);

void	rotation_calculation(t_list0 *A, t_list0 *B);
int		get_next_max(t_list0 *list, int value);
void	ft_sort_int_tab(int *tab, int size);
int		get_max(t_list0 *list);
int		get_min(t_list0 *list);
int		min(int n1, int n2);
int		max(int n1, int n2);
t_node	*pull(t_list0 *list, t_node *node);
void	push(t_list0 *list, t_node *node);
void	swap(t_list0 *list);
int		reverse_rotate(t_list0 *list);
int		rotate(t_list0 *list);
void	group_builder(t_list0 *list);
int		if_group(t_list0 *list, int group);
void	reset_rotations(t_node *node);
void	presort(t_list0	*A, t_list0 *B);
void	presort_five(t_list0	*A, t_list0 *B);
void	sort_large(t_list0 *A, t_list0 *B);
int		sort_three(t_list0 *A);
int		sort_five(t_list0 *A, t_list0 *B);
int		is_sorted(t_list0 *list);
t_node	*get_group_first(t_list0 *list, int group);
t_node	*get_min_cost(t_list0 *list, int group);
void	last_group_push(t_list0 *A, t_list0 *B);
void	clear(t_list0 **list);
int		fill_list(t_list0 *list, int argc, char *argv[]);
int		fill_list_from_args(t_list0 *list, int argc, char *argv[]);
int		fill_list_from_str(t_list0 *list, char **str);

#endif
