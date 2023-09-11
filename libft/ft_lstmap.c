/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:21:23 by bmarcono          #+#    #+#             */
/*   Updated: 2023/01/29 17:04:46 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*head;

	head = NULL;
	while (lst != NULL)
	{
		tmp = ft_lstnew((f)(lst -> content));
		if (!tmp)
		{
			(del)(lst);
		}
		ft_lstadd_back (&head, tmp);
		lst = lst -> next;
	}
	return (head);
}
