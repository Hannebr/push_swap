/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 14:17:57 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/18 14:21:52 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == 0)
		return ;
	while (lst->next != 0)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
	(*f)(lst->content);
}
