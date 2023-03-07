/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:51:52 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/07 13:10:50 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		i;

	result = (char *) malloc(ft_strlen(s1) + 1 * sizeof(char));
	if (result == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		result[i] = *((char *)s1 + i);
		i++;
	}
	result[i] = '\0';
	return (result);
}
