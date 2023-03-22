/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 17:38:53 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/20 16:59:34 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	t_list	*tmp;

	tmp = *stack_a->tail;
	*stack_a->tail = (*stack_a->tail)->prev;
	(*stack_a->tail)->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack_a->head;
	(*stack_a->head)->prev = tmp;
	*stack_a->head = tmp;
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	t_list	*tmp;

	tmp = *stack_b->tail;
	*stack_b->tail = (*stack_b->tail)->prev;
	(*stack_b->tail)->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack_b->head;
	(*stack_b->head)->prev = tmp;
	*stack_b->head = tmp;
	ft_printf("rb\n");
}

void	rra(t_stack *stack_a)
{
	t_list	*tmp;

	tmp = *stack_a->head;
	*stack_a->head = (*stack_a->head)->next;
	(*stack_a->head)->prev = NULL;
	tmp->prev = *stack_a->tail;
	(*stack_a->tail)->next = tmp;
	tmp->next = NULL;
	*stack_a->tail = tmp;
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	t_list	*tmp;

	tmp = *stack_b->head;
	*stack_b->head = (*stack_b->head)->next;
	(*stack_b->head)->prev = NULL;
	tmp->prev = *stack_b->tail;
	(*stack_b->tail)->next = tmp;
	tmp->next = NULL;
	*stack_b->tail = tmp;
	ft_printf("rrb\n");
}