/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hex_functions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 16:34:47 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/07 13:22:36 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhexlow(va_list ptr)
{
	unsigned int	num;
	int				length;

	num = va_arg(ptr, unsigned int);
	print_base("0123456789abcdef", 16, num);
	length = num_len(num, 16);
	if (num == 0)
		return (1);
	return (length);
}

int	ft_printhexup(va_list ptr)
{
	unsigned int	num;
	int				length;

	num = va_arg(ptr, unsigned int);
	print_base("0123456789ABCDEF", 16, num);
	length = num_len(num, 16);
	if (num == 0)
		return (1);
	return (length);
}

int	ft_printptr(va_list ptr)
{
	void	*address;
	int		length;

	address = va_arg(ptr, void *);
	write(1, "0x", 2);
	print_base("0123456789abcdef", 16, (unsigned long) address);
	if (address == NULL)
		return (3);
	length = num_len((unsigned long) address, 16) + 2;
	return (length);
}
