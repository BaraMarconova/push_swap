/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:59:54 by bmarcono          #+#    #+#             */
/*   Updated: 2023/02/22 18:26:47 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_uns_int_len(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_str_uitoa(char *str, unsigned int n, unsigned int len)
{
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len - 1] = (n % 10) + '0';
		n = n / 10;
		--len;
	}
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_uns_int_len(n);
	str = (char *)malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	ft_str_uitoa (str, n, len);
	return (str);
}

int	ft_print_u(unsigned int nb)
{
	int		len;
	char	*str;

	str = ft_uitoa(nb);
	len = ft_printstr (str);
	free(str);
	return (len);
}
