/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:34:54 by bmarcono          #+#    #+#             */
/*   Updated: 2023/08/20 16:19:26 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_len(int n)
{
	int	len;
	int	num;

	len = 1;
	num = 0;
	if (n == -2147483648)
		return (11);
	if (n >= 0 && n <= 9)
		return (1);
	if (n < 0)
	{
		num = -1 * n;
		len++;
	}
	else
		num = n;
	while (num / 10 != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

void	ft_str_itoa(char *str, int n, int len)
{
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -1 * n;
	}
	while (n > 0)
	{
		str[len - 1] = (n % 10) + '0';
		n = n / 10;
		--len;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = 0;
	len = ft_int_len(n);
	str = (char *)malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	ft_str_itoa (str, n, len);
	return (str);
}
