/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:44:24 by bmarcono          #+#    #+#             */
/*   Updated: 2023/02/20 19:34:39 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_print_p(void *p)
{
	int	len;

	len = 2;
	if (p == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	else
	{
		write (1, "0x", 2);
		len = len + ft_print_hex((unsigned long)p, 'x');
	}
	return (len);
}
