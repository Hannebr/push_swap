/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 11:48:40 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/07 13:14:19 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	char	*result;

	if (s1[0] == '\0')
	{
		result = ft_strdup("");
		return (result);
	}
	first = 0;
	last = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[first]) != 0 && first < ft_strlen(s1))
		first++;
	while (ft_strchr(set, s1[last]) != 0 && last > first)
		last--;
	result = ft_substr(s1, first, (last - first) + 1);
	return (result);
}
