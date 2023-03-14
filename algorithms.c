/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithms.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 15:21:10 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/14 16:04:54 by hbrouwer      ########   odam.nl         */
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
	while (*stack_b->tail)
		push(stack_a, stack_b, 1);
}

int is_sorted(t_stack *stack, int *sorted, int opt, int len)
{
	int i;
	t_list *tmp;

	if (opt == 1)
		i = len - 1;
	else
		i = 0;
	tmp = *stack->head;
	while (tmp)
	{
		if (tmp->number != sorted[i])
			return (0);
		if (opt == 1)
			i--;
		else
			i++;
		tmp = tmp->next;
	}
	return (1);
}

int get_pivot(t_stack *stack, int *sorted, int opt, int len)
{
    int 	*array;
	int 	i;
	int		j;
	t_list	*tmp;
	
	i = 0;
	tmp = *stack->head;
	if (opt == 1)
		j = len - 1;
	else
		j = 0;
	while (tmp->number == sorted[j])
	{
		i++;
		if (opt == 1)
			j--;
		else
			j++;
		tmp = tmp->next;
	}
	array = selection_sort(stack);
	return (array[(stack->length - i) / 2]);
}

int 	pushes_possible(t_stack *stack, int pivot, int opt)
{
	t_list *tmp;

	tmp = *stack->tail;
	while (tmp)
	{
		if (opt == 1 && tmp->number < pivot)
			return (1);
		if (opt == 2 && tmp->number >= pivot)
			return (1);
		tmp = tmp->prev;
	}
	return (0);
}

// void    quicksort_a(t_stack *stack_a, t_stack *stack_b, int *sorted, int len)
// {
// 	int	pivot;

// 	if (stack_a->length <= 3)
// 		return ;
// 	pivot = get_pivot(stack_a, sorted, 1, len);
// 	pushes = pivot_a_compare(stack_a, stack_b, pushes, pivot);
// 	quicksort_a(stack_a, stack_b, old_pushes - pushes);
// 	quicksort_b(stack_a, stack_b, pushes);
// }

// void    quicksort_b(t_stack *stack_a, t_stack *stack_b, int *sorted, int len)
// {
// 	int	pivot;
	
// 	if (stack_b->length <= 3)
// 		return ;

// 	pivot = get_median(stack_b);
// 	pivot_b_compare(stack_a, stack_b, pivot);
// 	quicksort_a(stack_a, stack_b, sorted);
// 	quicksort_b(stack_a, stack_b, sorted);
// }

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

void	bucketsort(t_stack *stack_a, t_stack *stack_b)
{
	int	*array;
	int	bucket_size;
	int	i[3];
	int	length;
	
	array = selection_sort(stack_a);
	length = stack_a->length;
	bucket_size = 5;
	i[0] = 0;
	while (i[0] < length)
	{
		if (i[0] + bucket_size > length)
			i[1] = length - i[0];
		else
			i[1] = bucket_size;
		i[2] = i[1];
		while (i[1] >= 0)
		{
			find_and_push(stack_a, stack_b, array[i[0] + i[1]]);
			i[1]--;
		}
		// print_stacks(stack_a, stack_b);
		push_and_rotate(stack_a, stack_b);
		// print_stacks(stack_a, stack_b);
		i[0] += i[2];
	}
	free(array);
}

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

void	sort_2(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->length == 2)
	{
		if ((*stack_a->tail)->number <= (*stack_a->head)->number)
			return ;
		else
			swap(stack_a, stack_b, 1);
	}
	// if (stack_b->length == 2)
	// {
	// 	if ((*stack_b->tail)->number <= (*stack_b->head)->number)
	// 		return ;
	// 	else
	// 		swap(stack_a, stack_b, 2);
	// }
}

void    sort_3(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->length == 3)
	{
		if ((*stack_a->tail)->prev->number >= (*stack_a->tail)->number && (*stack_a->tail)->prev->number <= (*stack_a->head)->number)
			return ;
		if ((*stack_a->tail)->prev->number >= (*stack_a->tail)->number && (*stack_a->tail)->prev->number >= (*stack_a->head)->number)
			rev_rotate(stack_a, stack_b, 1);
		if ((*stack_a->tail)->number >= (*stack_a->tail)->prev->number && (*stack_a->tail)->number >= (*stack_a->head)->number)
			rotate(stack_a, stack_b, 1);
		if ((*stack_a->tail)->number >= (*stack_a->tail)->prev->number && (*stack_a->tail)->number <= (*stack_a->head)->number)
			swap(stack_a, stack_b, 1);
	}
	// if (stack_b->length == 3)
	// {
	// 	if ((*stack_b->tail)->prev->number >= (*stack_b->tail)->number && (*stack_b->tail)->prev->number <= (*stack_b->head)->number)
	// 		return ;
	// 	if ((*stack_b->tail)->prev->number >= (*stack_b->tail)->number && (*stack_b->tail)->prev->number >= (*stack_b->head)->number)
	// 		rev_rotate(stack_a, stack_b, 2);
	// 	if ((*stack_b->tail)->number >= (*stack_b->tail)->prev->number && (*stack_b->tail)->number >= (*stack_b->head)->number)
	// 		rotate(stack_a, stack_b, 2);
	// 	if ((*stack_b->tail)->number >= (*stack_b->tail)->prev->number && (*stack_b->tail)->number <= (*stack_b->head)->number)
	// 		swap(stack_a, stack_b, 2);
	// }
}