/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:52:15 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/16 18:00:32 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_and_push(t_stack *stack_a, t_stack *stack_b, int num)
{
	t_list	*ptr;

	ptr = *stack_a->tail;
	while (ptr != NULL)
	{
		if (ptr->number == num)
		{
			while (*stack_a->tail != ptr)
				rotate(stack_a, stack_b, 1);
			push(stack_a, stack_b, 2);
			return ;
		}
		else
			ptr = ptr->prev;
	}
}

void	push_and_rotate(t_stack *stack_a, t_stack *stack_b)
{
	while (*stack_b->tail != NULL)
	{
		push(stack_a, stack_b, 1);
		rotate(stack_a, stack_b, 1);
	}
}