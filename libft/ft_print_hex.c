/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:41:56 by bmarcono          #+#    #+#             */
/*   Updated: 2023/02/20 19:33:45 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_hex_len(unsigned long nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb = nb / 16;
		len ++;
	}
	return (len);
}

void	ft_put_hex(unsigned long nb, char format)
{
	if (nb >= 16)
	{
		ft_put_hex ((nb / 16), format);
		ft_put_hex ((nb % 16), format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd (nb + '0', 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd ('a' + (nb - 10), 1);
			if (format == 'X')
				ft_putchar_fd ('A' + (nb - 10), 1);
		}
	}
}

int	ft_print_hex(unsigned long nb, char format)
{
	int	len;

	if (nb == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else
	{
		len = ft_hex_len(nb);
		ft_put_hex(nb, format);
	}
	len = ft_hex_len (nb);
	return (len);
}
