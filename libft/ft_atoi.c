/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:22:15 by bmarcono          #+#    #+#             */
/*   Updated: 2023/01/18 19:19:31 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	result;
	int	sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((s[i] != '\0') && ((s[i] == 32) || (s[i] >= 9 && s[i] <= 13)))
	{
		i++;
	}
	if (s[i] != '\0' && (s[i] == '-' || s[i] == '+'))
	{
		if (s[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
	{
		result = (10 * result) + (s[i] - '0');
		i++;
	}
	return (result * sign);
}
