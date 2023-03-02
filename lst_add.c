/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_add.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:45:57 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/02 14:16:05 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_newlst(int number)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		exit(0);
	new->number = number;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lstadd_back(t_stack *stack, t_list *new)
{
	if (*(stack->head) == NULL)
	{
		*(stack->head) = new;
		*(stack->tail) = new;
		stack->length++;
		return ;
	}
	new->next = NULL;
	new->prev = *(stack->tail);
	(*(stack->tail))->next = new;
	*(stack->tail) = new;
	stack->length++;
}
