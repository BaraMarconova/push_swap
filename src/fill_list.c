/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <bmarcono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:47:13 by bmarcono          #+#    #+#             */
/*   Updated: 2023/09/11 17:48:59 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_list_from_args(t_list0 *list, int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (validate_content(list, argv[i]) == -1)
			return (-1);
		else
			insert_node(list, ft_atoi(argv[i]));
		++i;
	}
	return (0);
}

int	fill_list_from_str(t_list0 *list, char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
	{
		if (validate_content(list, str[i]) == -1)
		{
			free(str);
			return (-1);
		}
		else
			insert_node(list, ft_atoi(str[i]));
		++i;
	}
	free(str);
	return (0);
}

int	fill_list(t_list0 *list, int argc, char *argv[])
{
	if (argc == 2)
		return (fill_list_from_str(list, ft_split(argv[1], ' ')));
	else
		return (fill_list_from_args(list, argc, argv));
	return (0);
}
