/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/17 13:42:24 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/20 16:50:17 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted_a(t_stack *stack_a, int *sorted, int len)
{
    int     i;
    t_list  *tmp;

    i = len - 1;
    tmp = *stack_a->head;
    while (tmp && i >= 0)
    {
        if (tmp->number != sorted[i])
            return (0);
        i--;
        tmp = tmp->next;
    }
    return (1);
}

int is_sorted_b(t_stack *stack_b, int *sorted, int len)
{
    int     i;
    t_list  *tmp;

    i = 0;
    tmp = *stack_b->head;
    while (tmp && i < len)
    {
        if (tmp->number != sorted[i])
            return (0);
        i++;
        tmp = tmp->next;
    }
    
    return (1);
}

int 	pushes_possible(t_stack *stack, int pivot, int opt)
{
	t_list *tmp;

	tmp = *stack->tail;
	while (tmp)
	{
		if (opt == 'A' && tmp->number <= pivot)
			return (1);
		if (opt == 'B' && tmp->number >= pivot)
			return (1);
		tmp = tmp->prev;
	}
	return (0);
}