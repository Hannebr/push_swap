/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:11:12 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/07 13:11:40 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	result = (char *)haystack;
	if (needle[0] == '\0')
		return (result);
	while (i < len && result[i])
	{
		j = 0;
		while (result[i + j] == needle[j] && result[i + j] && (i + j) < len)
		{
			j++;
			if (needle[j] == '\0')
				return (&result[i]);
		}
		i++;
	}
	return (0);
}
