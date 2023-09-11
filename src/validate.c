/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <bmarcono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:45:06 by bmarcono          #+#    #+#             */
/*   Updated: 2023/09/11 19:03:53 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	if (str[0] != '\0' && ((str[0] == '-' || str[0] == '+') \
				|| ft_isdigit(str[0])))
		return (1);
	return (0);
}

int	check_dublicates(t_list0 *list, int content)
{
	t_node	*temp;
	int		i;

	i = 0;
	if (list->head != NULL)
	{
		temp = list->head;
		while (i < list->size)
		{
			if (temp->content == content)
				return (-1);
			temp = temp->next;
			++i;
		}
	}
	return (0);
}

void	insert_node(t_list0 *list, int content)
{
	push(list, ft_lstnew(content));
	rotate(list);
}

int	validate_content(t_list0 *list, char *content)
{
	long	nbr;

	if (!is_number(content))
	{
		ft_printf("ERROR\n");
		return (-1);
	}
	nbr = ft_atoi(content);
	if (nbr < MIN_INT || nbr > MAX_INT)
	{
		ft_printf("ERROR\n");
		return (-1);
	}
	if (check_dublicates(list, nbr) == -1)
	{
		ft_printf("ERROR: Dublicated values\n");
		return (-1);
	}
	return (0);
}
