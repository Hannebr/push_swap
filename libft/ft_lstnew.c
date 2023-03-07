/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 19:31:17 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/07 13:09:05 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = (t_list *) malloc(sizeof(t_list));
	if (result == 0)
		return (0);
	result->content = content;
	result->next = 0;
	return (result);
}
