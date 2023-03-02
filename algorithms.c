/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithms.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 15:21:10 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/02 16:13:51 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    smallest_alg(t_stack *stack_a, t_stack *stack_b)
{
    t_list  *smallest;
    int     index_smallest;
    int     index;
    t_list  *check;
    
    while (*stack_a->tail)
    {
        smallest = *stack_a->tail;
        index = index_smallest = 0;
        check = *stack_a->tail;
        while (check)
        {
            if (check->number < smallest->number)
            {
                smallest = check;
                index_smallest = index;
            }
            index++;
            check = check->prev;
        }
        while (*stack_a->tail != smallest)
        {
            if (index_smallest < stack_a->length / 2)
            {
                rotate(stack_a, stack_b, 1);
                index_smallest--;
            }
            else
            {
                rev_rotate(stack_a, stack_b, 1);
                index_smallest++;
            }
        }
        push(stack_a, stack_b, 2);
    }
}