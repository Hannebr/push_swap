/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 17:25:30 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/23 14:00:58 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp;

	tmp = *stack_b->tail;
	if (tmp == *stack_b->head)
	{
		*stack_b->tail = NULL;
		*stack_b->head = NULL;
	}
	else
	{
		*stack_b->tail = (*stack_b->tail)->prev;
		(*stack_b->tail)->next = NULL;
	}
	tmp->next = NULL;
	tmp->prev = NULL;
	ft_lstadd_back(stack_a, tmp);
	stack_b->length--;
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp;

	tmp = *stack_a->tail;
	if (tmp == *stack_a->head)
	{
		*stack_a->tail = NULL;
		*stack_a->head = NULL;
	}
	else
	{
		*stack_a->tail = (*stack_a->tail)->prev;
		(*stack_a->tail)->next = NULL;	
	}
	tmp->next = NULL;
	tmp->prev = NULL;
	ft_lstadd_back(stack_b, tmp);
	stack_a->length--;
	ft_printf("pb\n");
}
