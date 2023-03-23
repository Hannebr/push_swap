/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 16:56:35 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/23 12:13:19 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	int	temp;

	temp = (*stack_a->tail)->prev->number;
	(*stack_a->tail)->prev->number = (*stack_a->tail)->number;
	(*stack_a->tail)->number = temp;
	temp = (*stack_a->tail)->prev->index;
	(*stack_a->tail)->prev->index = (*stack_a->tail)->index;
	(*stack_a->tail)->index = temp;
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	int	temp;

	temp = (*stack_b->tail)->prev->number;
	(*stack_b->tail)->prev->number = (*stack_b->tail)->number;
	(*stack_b->tail)->number = temp;
	temp = (*stack_b->tail)->prev->index;
	(*stack_b->tail)->prev->index = (*stack_b->tail)->index;
	(*stack_b->tail)->index = temp;
	ft_printf("sb\n");
}
