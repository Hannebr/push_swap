/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 15:49:18 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/07 13:08:29 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static size_t	num_len(int n)
{
	size_t	length;

	length = 0;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static char	*ft_strrev(char *str, size_t len)
{
	size_t	i;
	size_t	j;
	char	temp;

	i = 0;
	j = len - 1;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

static char	*convert_to_str(char *dest, int n, size_t length)
{
	size_t				i;
	unsigned int		tmp;

	i = 1;
	if (n < 0)
		tmp = n * -1;
	else
		tmp = n;
	while (i <= length)
	{
		dest[i] = (tmp % 10) + '0';
		tmp /= 10;
		i++;
	}
	if (n < 0)
		dest[i - 1] = '-';
	return (dest);
}

char	*ft_itoa(int n)
{
	size_t	length;
	char	*str;

	length = num_len(n);
	if (n <= 0)
		length++;
	str = (char *) malloc((length + 1) * sizeof(char));
	if (str == 0)
		return (0);
	str[0] = '\0';
	str = convert_to_str(str, n, length);
	str = ft_strrev(str, length + 1);
	return (str);
}
