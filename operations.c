/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:52:15 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/02/22 11:18:21 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_stack *stack_a, t_stack *stack_b, int option)
{
    if (option == 1)
    {
        swap_stack(stack_a);
        printf("sa\n");
    }
    else if (option == 2)
    {
        swap_stack(stack_b);
        printf("sb\n")
    }
    else if (option == 0)
    {
        swap_stack(stack_a);
        swap_stack(stack_b);
        printf("ss\n")
    }
}

void    swap_stack(t_stack *stack)
{
    int temp;
    
    temp = (*stack->tail)->prev->number;
    (*stack->tail)->prev->number = (*stack->tail)->number;
    (*stack->tail)->number = temp;
}