/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:36:21 by bmarcono          #+#    #+#             */
/*   Updated: 2023/01/17 16:33:07 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t	i;
	char	*d;

	d = (char *)dest;
	i = 0;
	while (i < len)
	{
		d[i] = (char)c;
		i++;
	}
	return (dest);
}
