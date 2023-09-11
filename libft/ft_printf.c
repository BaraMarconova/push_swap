/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarcono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:54:09 by bmarcono          #+#    #+#             */
/*   Updated: 2023/02/22 18:16:04 by bmarcono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printint(int nb)
{
	char	*str;
	int		len;

	str = ft_itoa(nb);
	len = ft_printstr (str);
	free(str);
	return (len);
}

int	ft_format(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_printchar(va_arg(args, int));
	else if (c == 's')
		len = ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		len = ft_print_p(va_arg(args, void *));
	else if (c == 'd')
		len = ft_printint(va_arg(args, int));
	else if (c == 'i')
		len = ft_printint(va_arg(args, int));
	else if (c == 'u')
		len = ft_print_u(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		len = ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		len = ft_printchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len = len + ft_format(args, str[i + 1]);
			i++;
		}
		else
			len = len + ft_printchar(str[i]);
		i++;
	}
	va_end (args);
	return (len);
}
// int	main(void)
// {
// 	int	len;
// 	int	len2;
// 	// char string[] = "ahoj";
// 	// char string2[] = "cau";
// 	unsigned int	test;
// 	test = -123;	
// 	len = ft_printf("my printf: %u\n", test);
// 	printf("my printf len = %d\n", len);
// 	len2 = printf("or printf: %u\n", test);
// 	printf("or printf len = %d\n", len2);
// 	return (0);
// }
