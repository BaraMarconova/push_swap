/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:02:32 by bmarcono          #+#    #+#             */
/*   Updated: 2023/02/01 19:49:49 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*s;
	size_t		test;

	test = nmemb * size;
	if (nmemb == 0 || size == 0)
	{
		s = malloc(0);
		return (s);
	}
	if (test / size != nmemb)
		return (NULL);
	s = (void *)malloc(nmemb * size);
	if (!s)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}
