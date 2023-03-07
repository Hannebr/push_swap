/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 17:13:41 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/07 13:22:14 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const int	(*g_function_array[])(va_list arg) = {
['c'] = ft_printchar,
['s'] = ft_printstr,
['p'] = ft_printptr,
['d'] = ft_printdec,
['i'] = ft_printint,
['u'] = ft_printunsigned,
['x'] = ft_printhexlow,
['X'] = ft_printhexup,
['%'] = ft_printperc
};

int	ft_printf(const char *str, ...)
{
	int			i;
	int			len;
	va_list		ptr;

	va_start(ptr, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			len += g_function_array[(int)str[i + 1]](ptr);
			i++;
		}
		else if (str[i] != '%')
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(ptr);
	return (len);
}

// #include <stdio.h>

// int main(void)
// {
// 	char a = '4';
// 	int res1 = ft_printf("hello %p", &a);
// 	printf("\n");
// 	int res2 = printf("hello %p", &a);
// 	printf("\n");

// 	printf("original: %d		mine: %d\n", res2, res1);
// }
