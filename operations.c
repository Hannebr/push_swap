/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:52:15 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/02 14:14:31 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack_a, t_stack *stack_b, int option)
{
	if (option == 1)
	{
		swap_stack(stack_a);
		printf("sa\n");
	}
	if (option == 2)
	{
		swap_stack(stack_b);
		printf("sb\n");
	}
	else if (option == 0)
	{
		swap_stack(stack_a);
		swap_stack(stack_b);
		printf("ss\n");
	}
}

void	swap_stack(t_stack *stack)
{
	int	temp;

	temp = (*stack->tail)->prev->number;
	(*stack->tail)->prev->number = (*stack->tail)->number;
	(*stack->tail)->number = temp;
}

void	push(t_stack *stack_a, t_stack *stack_b, int option)
{
	if (option == 1)
	{
		push_stack(stack_b, stack_a);
		printf("pa\n");
	}
	else if (option == 2)
	{
		push_stack(stack_a, stack_b);
		printf("pb\n");
	}
}

void	push_stack(t_stack *src, t_stack *dst)
{
	t_list	*node;
	
	node = (*src->tail);
	(*src->tail) = (*src->tail)->prev;
	node->next = NULL;
	node->prev = NULL;
	ft_lstadd_back(dst, node);
	src->length--;
}

void	rotate(t_stack *stack_a, t_stack *stack_b, int option)
{
	if (option == 1)
	{
		rotate_stack(stack_a);
		printf("ra\n");
	}
	else if (option == 2)
	{
		rotate_stack(stack_b);
		printf("rb\n");
	}
	else if (option == 0)
	{
		rotate_stack(stack_a);
		rotate_stack(stack_b);
		printf("rr\n");
	}
}

void	rotate_stack(t_stack *stack)
{
	t_list	*node;

	node = *stack->tail; 
	*stack->tail = (*stack->tail)->prev;
	(*stack->tail)->next = NULL;
	node->prev = NULL;
	node->next = *stack->head;
	(*stack->head)->prev = node;
	*stack->head = node;
}

void	rev_rotate(t_stack *stack_a, t_stack *stack_b, int option)
{
	if (option == 1)
	{
		rev_rotate_stack(stack_a);
		printf("rra\n");
	}
	else if (option == 2)
	{
		rev_rotate_stack(stack_b);
		printf("rrb\n");
	}
	else if (option == 0)
	{
		rev_rotate_stack(stack_a);
		rev_rotate_stack(stack_b);
		printf("rrr\n");
	}
}

void	rev_rotate_stack(t_stack *stack)
{
	t_list	*node;

	node = *stack->head;
	*stack->head = (*stack->head)->next;
	(*stack->head)->prev = NULL;
	node->prev = *stack->tail;
	(*stack->tail)->next = node;
	*stack->tail = node;
}