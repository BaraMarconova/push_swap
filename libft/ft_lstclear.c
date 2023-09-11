/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:35:33 by bmarcono          #+#    #+#             */
/*   Updated: 2023/01/28 16:24:39 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		*lst = (*lst)-> next;
		(del)(tmp -> content);
		free(tmp);
		tmp = *lst;
	}
	lst = NULL;
}
