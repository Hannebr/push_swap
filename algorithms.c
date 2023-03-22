/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithms.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 15:21:10 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/22 23:52:45 by hbrouwer      ########   odam.nl         */
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

int	get_pivot_a(t_stack *stack, int *sorted, int len)
{
	int		*array;
	int		offset;
	int		i;
	int		pivot;
	t_list	*tmp;

	offset = 0;
	tmp = *stack->head;
	i = len - 1;
	while (tmp->number == sorted[i])
	{
		offset++;
		i--;
		tmp = tmp->next;
	}
	array = selection_sort(stack);
	pivot = array[(stack->length - offset)/ 2];
	return (free(array), pivot);
}

int	get_pivot_b(t_stack *stack, int *sorted)
{
	int		*array;
	int		offset;
	int		pivot;
	t_list	*tmp;

	offset = 0;
	tmp = *stack->head;
	while (tmp->number == sorted[offset])
	{
		offset++;
		tmp = tmp->next;
	}
	array = selection_sort(stack);
	pivot = array[((stack->length - offset) / 2) + offset];
	return (free(array), pivot);
}

void    quicksort_a(t_stack *stack_a, t_stack *stack_b, int *sorted, int len)
{
	int	pivot;

	if (is_sorted_a(stack_a, sorted, len) && is_sorted_b(stack_b, sorted, len))
		return ;
	if (stack_a->length == 3)
		sort_3_a(stack_a);
	else if (stack_a->length == 2)
		sort_2_a(stack_a);
	else
	{
		pivot = get_pivot_a(stack_a, sorted, len);
		// ft_printf("\npivot_a = %i\n\n", pivot);
		// print_stacks(stack_a, stack_b);
		push_pivot_a(stack_a, stack_b, pivot);
		// print_stacks(stack_a, stack_b);
	}
	if (!(is_sorted_a(stack_a, sorted, len)))
		quicksort_a(stack_a, stack_b, sorted, len);
	if (!(is_sorted_b(stack_b, sorted, len)))
	{
		stack_a->round = 1;
		quicksort_b(stack_a, stack_b, sorted, len);
	}
}

void    quicksort_b(t_stack *stack_a, t_stack *stack_b, int *sorted, int len)
{
	int	pivot;
	
	if (is_sorted_a(stack_a, sorted, len) && is_sorted_b(stack_b, sorted, len))
		return ;
	if (stack_b->length == 3)
		sort_3_b(stack_b);
	else if (stack_b->length == 2)
		sort_2_b(stack_b);
	else
	{
		pivot = get_pivot_b(stack_b, sorted);
		// ft_printf("\npivot_b = %i\n\n", pivot);
		// print_stacks(stack_a, stack_b);
		push_pivot_b(stack_a, stack_b, pivot);
		// print_stacks(stack_a, stack_b);
	}
	if (!(is_sorted_b(stack_b, sorted, len)))
		quicksort_b(stack_a, stack_b, sorted, len);
	if (!(is_sorted_a(stack_a, sorted, len)))
	{
		stack_b->round = 1;
		quicksort_a(stack_a, stack_b, sorted, len);
	}
}

void	push_pivot_a(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int	rotates;
	
	rotates = 0;
	while (pushes_possible(stack_a, pivot, 'A'))
	{
		if ((*stack_a->tail)->number <= pivot)
			pb(stack_a, stack_b);
		else
		{
			ra(stack_a);
			rotates++;
		}	
	}
	if (stack_a->round != 0)
	{
		while (rotates > 0)
		{
			rra(stack_a);
			rotates--;
		}
	}
}

void	push_pivot_b(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int	rotates;

	rotates = 0;
	while(pushes_possible(stack_b, pivot, 'B'))
	{
		if ((*stack_b->tail)->number >= pivot)
			pa(stack_a, stack_b);
		else
		{
			rb(stack_b);
			rotates++;
		}
	}
	if (stack_b->round != 0)
	{
		while (rotates > 0)
		{
			rrb(stack_b);
			rotates--;
		}
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