/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 11:19:10 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/07 13:11:03 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	destlen;

	destlen = ft_strlen(dst);
	i = 0;
	j = destlen;
	if (dstsize - 1 < destlen || dstsize == 0)
		return (ft_strlen(src) + dstsize);
	while (j < dstsize - 1 && src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (destlen + ft_strlen(src));
}
