/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 16:59:04 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/07 13:09:44 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == 0 && src == 0)
		return (0);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else
	{
		i = len - 1;
		while (i >= 0 && !(i > len))
		{
			*((char *)dst + i) = *((char *)src + i);
			i--;
		}
		return ((void *)dst);
	}
}
