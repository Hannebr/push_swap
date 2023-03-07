/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 14:02:24 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/07 13:08:42 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (*lst == 0)
		return ;
	while ((*lst)->next != 0)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		(*del)(tmp->content);
		free(tmp);
	}
	tmp = *lst;
	*lst = 0;
	(*del)(tmp->content);
	free(tmp);
}
