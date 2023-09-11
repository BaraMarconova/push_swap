/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:58:10 by bmarcono          #+#    #+#             */
/*   Updated: 2023/01/21 19:01:01 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*newstr;
	int		i;
	int		j;
	int		k;

	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = malloc(sizeof(char) * len + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i] != '\0')
	{
		newstr[k++] = s1[i++];
	}
	j = 0;
	while (s2[j] != '\0')
	{
		newstr[i++] = s2[j++];
	}
	newstr[i] = '\0';
	return (newstr);
}
