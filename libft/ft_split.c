/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 13:28:03 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/07 13:10:41 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word_length(size_t index, char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[index] != c && s[index] != '\0')
	{
		index++;
		len++;
	}
	return (len);
}

static int	count_words(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (s[0] != c && s[0] != '\0')
	{
		count = 1;
		i = 1;
	}
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

static char	**ft_free(int i, char **result)
{
	while (i >= 0)
	{
		free(result[i]);
		i--;
	}
	free(result);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;
	int		i;
	size_t	index;

	count = count_words(s, c);
	result = (char **) malloc((count + 1) * sizeof(char *));
	if (result == 0)
		return (0);
	i = 0;
	index = 0;
	while (i < count)
	{
		while (s[index] == c)
			index++;
		result[i] = ft_substr(s, index, get_word_length(index, s, c));
		if (result[i] == 0)
			return (ft_free(i, result));
		i++;
		index += get_word_length(index, s, c);
	}
	result[i] = 0;
	return (result);
}
