/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 18:05:44 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/07 13:22:50 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_base(char *baseset, int base, unsigned long num)
{
	char	c;

	if (num / base > 0)
		print_base(baseset, base, num / base);
	c = baseset[num % base];
	write(1, &c, 1);
}

unsigned int	print_negative(int n)
{
	unsigned int	num;

	if (n < 0)
	{
		num = n * -1;
		write(1, "-", 1);
	}
	else
		num = n;
	return (num);
}

int	num_len(unsigned long n, int base)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		n /= base;
		length++;
	}
	return (length);
}

// int main(void)
// {  
//     print_base("0123456789ABCDEF", 16, -4892);
//     write(1, "\n", 1);
//     print_base("0123456789", 10, -4892);
//     write(1, "\n", 1);
//     print_base("01234567", 8, -4892);
//     write(1, "\n", 1);
//     print_base("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26, -4892);
// }