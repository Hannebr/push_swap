/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 12:48:42 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/07 13:10:30 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		write(fd, "-", 1);
		num = n * -1;
	}
	else
		num = n;
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		num %= 10;
	}
	if (num < 10)
	{
		num += '0';
		write(fd, &num, 1);
	}
}
