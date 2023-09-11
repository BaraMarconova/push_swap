/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:27:00 by bmarcono          #+#    #+#             */
/*   Updated: 2023/01/31 20:06:44 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	return (i);
}

int	ft_find_end(char const *s1, char const *set)
{
	int	len;

	len = ft_strlen(s1);
	while (len > 0 && ft_strrchr(set, s1[len - 1]))
		len--;
	return (len - 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		start;
	int		end;

	if (ft_strlen(s1) == 0)
		return (ft_strdup(s1));
	if (ft_strlen(set) == 0)
		return (ft_strdup(s1));
	start = ft_find_start(s1, set);
	end = ft_find_end(s1, set);
	if (end < start)
		newstr = ft_strdup("");
	else
	{
		newstr = (char *)malloc(sizeof(char) * (end - start + 2));
		if (!newstr)
			return (NULL);
		ft_strlcpy(newstr, &s1[start], (end - start + 2));
	}
	return (newstr);
}
