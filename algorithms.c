/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithms.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 15:21:10 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/23 16:58:59 by hbrouwer      ########   odam.nl         */
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
				ra(stack_a);
				index_smallest--;
			}
			else
			{
				rra(stack_a);
				index_smallest++;
			}
		}
		pb(stack_a, stack_b);
	}
	while (*stack_b->tail)
		pa(stack_a, stack_b);
}

int	get_pivot_a(t_stack *stack, int len)
{
	int		*array;
	int		offset;
	int		i;
	int		pivot;
	t_list	*tmp;

	offset = 0;
	tmp = *stack->head;
	i = len;
	while (tmp->index == i)
	{
		offset++;
		i--;
		tmp = tmp->next;
	}
	array = selection_sort(stack);
	pivot = array[(stack->length - offset)/ 2];
	return (free(array), pivot);
}

int	get_pivot_b(t_stack *stack)
{
	int		*array;
	int		offset;
	int		i;
	int		pivot;
	t_list	*tmp;

	offset = 0;
	i = 1;
	tmp = *stack->head;
	while (tmp->index == i)
	{
		offset++;
		i++;
		tmp = tmp->next;
	}
	array = selection_sort(stack);
	pivot = array[((stack->length - offset) / 2) + offset];
	return (free(array), pivot);
}

void    quicksort_a(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	pivot;

	if (!is_sorted_a(stack_a, len) || !is_sorted_b(stack_b, len))
	{
		if (stack_a->length == 3)
			sort_3_a(stack_a);
		else if (stack_a->length == 2)
			sort_2_a(stack_a);
		else
		{
			pivot = get_pivot_a(stack_a, len);
			push_pivot_a(stack_a, stack_b, pivot);
		}
		if (stack_a->round != 0)
		{
			while ((*stack_a->head)->index != len)
				rra(stack_a);
			while ((*stack_b->head)->index != 1)
				rrb(stack_b);
		}
	}
	if (!(is_sorted_a(stack_a, len)))
		quicksort_a(stack_a, stack_b, len);
	if (!(is_sorted_b(stack_b, len)))
	{
		stack_a->round = 1;
		quicksort_b(stack_a, stack_b, len);
	}
	while (*stack_b->tail)
		pa(stack_a, stack_b);
}

void    quicksort_b(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	pivot;
	
	if (!is_sorted_a(stack_a, len) || !is_sorted_b(stack_b, len))
	{
		if (stack_b->length == 3)
			sort_3_b(stack_b);
		else if (stack_b->length == 2)
			sort_2_b(stack_b);
		else
		{
			pivot = get_pivot_b(stack_b);
			push_pivot_b(stack_a, stack_b, pivot, len);
		}
		while ((*stack_b->head)->index != 1)
			rrb(stack_b);
		while ((*stack_a->head)->index != len)
			rra(stack_a);
	}
	if (!(is_sorted_b(stack_b, len)))
		quicksort_b(stack_a, stack_b, len);
	if (!(is_sorted_a(stack_a, len)))
	{
		stack_b->round = 1;
		quicksort_a(stack_a, stack_b, len);
	}
	while (*stack_b->tail)
		pa(stack_a, stack_b);
}

void	push_pivot_a(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	while (pushes_possible(stack_a, pivot, 'A'))
	{
		if ((*stack_a->tail)->number < pivot)
		{
			if (stack_a->round != 0)
				placement_b(stack_a, stack_b);
			else
				pb(stack_a, stack_b);
		}
		else
			ra(stack_a);
	}
}

void	push_pivot_b(t_stack *stack_a, t_stack *stack_b, int pivot, int len)
{
	while(pushes_possible(stack_b, pivot, 'B'))
	{
		if ((*stack_b->tail)->number >= pivot)
			placement_a(stack_a, stack_b, len);
		else
			rb(stack_b);
	}
}

void	placement_a(t_stack *stack_a, t_stack *stack_b, int len)
{
	if ((*stack_b->tail)->index == (*stack_a->tail)->index - 1)
		pa(stack_a, stack_b);
	else if ((*stack_a->head)->index == len || (*stack_b->tail)->index > (*stack_a->head)->index)
	{
		if ((*stack_a->tail)->index != (*stack_a->tail)->prev->index - 1)
			ra(stack_a);
		pa(stack_a, stack_b);
		while ((*stack_a->tail)->index != (*stack_a->tail)->prev->index - 1)
			ra(stack_a);
	}
	else if ((*stack_b->tail)->index < (*stack_a->head)->index)
	{
		while ((*stack_b->tail)->index < (*stack_a->head)->index && (*stack_a->head)->index != len)
			rra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		// while ((*stack_a->tail)->index != (*stack_a->tail)->prev->index - 1)
		// 	ra(stack_a);
	}
}

void	placement_b(t_stack *stack_a, t_stack *stack_b)
{
	if ((*stack_a->tail)->index == (*stack_b->tail)->index + 1)
		pb(stack_a, stack_b);
	else if ((*stack_b->head)->index == 1 || (*stack_a->tail)->index < (*stack_b->head)->index)
	{
		if ((*stack_b->tail)->index != (*stack_b->tail)->prev->index + 1)
			rb(stack_b);
		pb(stack_a, stack_b);
		while ((*stack_b->tail)->index != (*stack_b->tail)->prev->index + 1)
			rb(stack_b);
	}
	else if ((*stack_a->tail)->index > (*stack_b->head)->index)
	{
		while ((*stack_a->tail)->index > (*stack_b->head)->index && (*stack_b->head)->index != 1)
			rrb(stack_b);
		pb(stack_a, stack_b);
		rb(stack_b);
		// while ((*stack_b->tail)->index != (*stack_b->tail)->prev->index + 1)
		// 	rb(stack_b);
	}
}

// int	pivot_a_compare(t_stack *stack_a, t_stack *stack_b, int pivot)
// {
// 	int		i;
// 	int		number_p;

// 	i = 0;
// 	number_p = 0;
// 	while (i < pushes)
// 	{
// 		if ((*stack_a->tail)->number < pivot)
// 			push(stack_a, stack_b, 2);
// 		else
// 			rotate(stack_a, stack_b, 1);
// 		i++;
// 		print_stacks(stack_a, stack_b);
// 	}
// 	return (number_p);
// }

// int	pivot_b_compare(t_stack *stack_a, t_stack *stack_b, int pivot)
// {
// 	int		i;
// 	int		number_p;

// 	i = 0;
// 	number_p = 0;
// 	while (i < pushes)
// 	{
// 		if ((*stack_b->tail)->number > pivot)
// 			push(stack_a, stack_b, 1);
// 		else
// 			rotate(stack_a, stack_b, 2);
// 		i++;
// 		print_stacks(stack_a, stack_b);
// 	}
// 	return (number_p);
// }

// void	bucketsort(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	*array;
// 	int	bucket_size;
// 	int	i[3];
// 	int	length;
	
// 	array = selection_sort(stack_a);
// 	length = stack_a->length;
// 	bucket_size = 5;
// 	i[0] = 0;
// 	while (i[0] < length)
// 	{
// 		if (i[0] + bucket_size > length)
// 			i[1] = length - i[0];
// 		else
// 			i[1] = bucket_size;
// 		i[2] = i[1];
// 		while (i[1] >= 0)
// 		{
// 			find_and_push(stack_a, stack_b, array[i[0] + i[1]]);
// 			i[1]--;
// 		}
// 		// print_stacks(stack_a, stack_b);
// 		push_and_rotate(stack_a, stack_b);
// 		// print_stacks(stack_a, stack_b);
// 		i[0] += i[2];
// 	}
// 	free(array);
// }

// int     get_median(t_stack *stack)
// {
// 	int     *array;
// 	int     median;

// 	array = selection_sort(stack);
// 	median = array[(stack->length)/2];
// 	free(array);
// 	return (median);
// }

int *selection_sort(t_stack *stack)
{
	int 	i;
	int 	j;
	int     *array;
	t_list  *ptr;
	
	array = (int *) malloc(stack->length * sizeof(int));
	if (!array)
		exit(0);
	i = 0;
	ptr = *stack->head;
	while (i < stack->length)
	{
		array[i] = ptr->number;
		ptr = ptr->next;
		i++;
	}
	i = 0;
	while (i < stack->length - 1)
	{
		j = i + 1;
		while (j < stack->length)
		{
			if (array[i] > array[j])
				swap_num(&array[i], &array[j]);
			j++;
		}
		i++;
	}
	return (array);
}

void    swap_num(int *a, int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_2_a(t_stack *stack_a)
{
	if (stack_a->length == 2)
	{
		if ((*stack_a->tail)->number <= (*stack_a->head)->number)
			return ;
		else
			sa(stack_a);
	}
}

void	sort_2_b(t_stack *stack_b)
{
	if (stack_b->length == 2)
	{
		if ((*stack_b->tail)->number >= (*stack_b->head)->number)
			return ;
		else
			sb(stack_b);
	}
}

void    sort_3_a(t_stack *stack_a)
{
	if ((*stack_a->tail)->prev->number > (*stack_a->tail)->number && (*stack_a->tail)->prev->number < (*stack_a->head)->number)
		return ;
	else if ((*stack_a->tail)->number < (*stack_a->tail)->prev->number && (*stack_a->tail)->number > (*stack_a->head)->number)
		rra(stack_a);
	else if ((*stack_a->head)->number > (*stack_a->tail)->prev->number && (*stack_a->head)->number < (*stack_a->tail)->number)
		ra(stack_a);
	else if ((*stack_a->tail)->number > (*stack_a->tail)->prev->number && (*stack_a->tail)->number < (*stack_a->head)->number)
		sa(stack_a);
	else if ((*stack_a->head)->number > (*stack_a->tail)->number && (*stack_a->head)->number < (*stack_a->tail)->prev->number)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if ((*stack_a->tail)->prev->number < (*stack_a->tail)->number && (*stack_a->tail)->prev->number > (*stack_a->head)->number)
	{
		ra(stack_a);
		sa(stack_a);
	}
}

void    sort_3_b(t_stack *stack_b)
{
	if ((*stack_b->tail)->prev->number < (*stack_b->tail)->number && (*stack_b->tail)->prev->number > (*stack_b->head)->number)
		return ;
	else if ((*stack_b->tail)->number > (*stack_b->tail)->prev->number && (*stack_b->tail)->number < (*stack_b->head)->number)
		rrb(stack_b);
	else if ((*stack_b->head)->number < (*stack_b->tail)->prev->number && (*stack_b->head)->number > (*stack_b->tail)->number)
		rb(stack_b);
	else if ((*stack_b->tail)->number < (*stack_b->tail)->prev->number && (*stack_b->tail)->number > (*stack_b->head)->number)
		sb(stack_b);
	else if ((*stack_b->tail)->prev->number > (*stack_b->tail)->number && (*stack_b->tail)->prev->number < (*stack_b->head)->number)
	{
		rb(stack_b);
		sb(stack_b);
	}
	else if ((*stack_b->head)->number > (*stack_b->tail)->prev->number && (*stack_b->head)->number < (*stack_b->tail)->number)
	{
		rrb(stack_b);
		sb(stack_b);
	}
}