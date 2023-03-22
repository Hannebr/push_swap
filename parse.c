/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 15:40:40 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/22 23:50:08 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **parse_input(int *argc, char **argv)
{
	char	**input;
	
	if (*argc < 2)
		exit(0);
	else if (*argc == 2)
	{
		input = ft_split(argv[1], ' ');
		*argc = count_words(argv[1], ' ');
	}
	else
	{
		input = trim_input(argv, *argc);
		*argc -= 1;
	}
	if (!is_valid_input(input, *argc))
	{
		ft_printf("Error\n");
		free(input);
		exit(0);
	}
	return (input);
}

char	**trim_input(char **argv, int argc)
{
	char	**input;
	int		i;

	input = (char **) malloc((argc - 1) * sizeof(char *));
	if (!input)
		exit(0);
	i = 0;
	while (i + 1 < argc)
	{
		input[i] = ft_strdup(argv[i + 1]);
		if (!input[i])
			exit(0);
		i++;
	}
	return (input);
}

int is_valid_input(char **input, int argc)
{
	int		i;

	i = 0;
	while (i < argc)
	{
		if (!is_valid_int(input[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_int(char *str)
{
	int		i;
	long 	nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + str[i] - '0';
		if ((sign == 1 && nb > INT_MAX) || (sign == -1 && nb > (long)INT_MAX + 1))
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	has_duplicates(t_stack *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *stack->head;
	while (tmp1->next)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp2->number == tmp1->number)
			{
				ft_printf("Error\n");
				return (1);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}