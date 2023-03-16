/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 16:56:35 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/16 17:58:54 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	int	temp;

	temp = (*stack_a->tail)->prev->number;
	(*stack_a->tail)->prev->number = (*stack_a->tail)->number;
	(*stack_a->tail)->number = temp;
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	int	temp;

	temp = (*stack_b->tail)->prev->number;
	(*stack_b->tail)->prev->number = (*stack_b->tail)->number;
	(*stack_b->tail)->number = temp;
	ft_printf("sb\n");
}
