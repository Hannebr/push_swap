/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 10:56:55 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/23 14:05:10 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_a(int argc, char **input, t_stack *stack_a)
{
	int		num;
	t_list	*new;

	stack_a->head = (t_list **) malloc(sizeof(t_list *));
	if (!stack_a->head)
		exit(0);
	stack_a->tail = (t_list **) malloc(sizeof(t_list *));
	if (!stack_a->tail)
		exit(0);
	*(stack_a->head) = NULL;
	stack_a->length = 0;
	stack_a->round = 0;
	while (argc > 0)
	{
		num = ft_atoi(input[argc - 1]);
		new = ft_newlst(num);
		ft_lstadd_back(stack_a, new);
		argc--;
	}
}

void	assign_index(t_stack *stack)
{
	t_list	*tmp;
	t_list	*t_small;
	int		index;
	int		smallest;
	int		last;
	
	index = 1;
	tmp = *stack->tail;
	last = INT_MIN;
	while (index <= stack->length)
	{
		smallest = INT_MAX;
		tmp = *stack->tail;
		while (tmp)
		{
			if (tmp->number > last && tmp->number < smallest)
			{
				smallest = tmp->number;
				t_small = tmp;
			}
			tmp = tmp->prev;
		}
		t_small->index = index;
		last = t_small->number;
		index++;
	} 
}

void	init_b(t_stack *stack_b)
{
	stack_b->head = (t_list **) malloc(sizeof(t_list *));
	if (!stack_b->head)
		exit (0);
	stack_b->tail = (t_list **) malloc(sizeof(t_list *));
	if (!stack_b->tail)
		exit(0);
	*(stack_b->head) = NULL;
	*(stack_b->tail) = NULL;
	stack_b->length = 0;
	stack_b->round = 0;
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*ptr_a;
	t_list	*ptr_b;
	
	ft_printf("-------------------------------------\nA:		|		B:\n		|\n");
	ptr_a = *stack_a->tail;
	ptr_b = *stack_b->tail;
	while (ptr_a != NULL || ptr_b != NULL)
	{
		if (ptr_a != NULL && ptr_b != NULL)
		{
			ft_printf("%i		|		%i\n", (ptr_a)->number, (ptr_b)->number);
			ptr_a = (ptr_a)->prev;
			ptr_b = (ptr_b)->prev;
		}
		else if (ptr_b == NULL)
		{
			ft_printf("%i		|\n", (ptr_a)->number);
			ptr_a = (ptr_a)->prev;
		}
		else if (ptr_a == NULL)
		{
			ft_printf("		|		%i\n", (ptr_b)->number);
			ptr_b = (ptr_b)->prev;
		}
	}
	ft_printf("-------------------------------------\n");
}

void checkLeaks() {
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	// t_list	*tmp;
	char	**input;

	stack_a = (t_stack *) malloc(sizeof(t_stack));
	if (!stack_a)
		exit(0);
	stack_b = (t_stack *) malloc(sizeof(t_stack));
	if (!stack_b)
		exit(0);
	input = parse_input(&argc, argv);
	init_a(argc, input, stack_a);
	free_input(input, argc);
	if (has_duplicates(stack_a))
		exit(0);
	init_b(stack_b);
	assign_index(stack_a);
	// tmp = *stack_a->head;
	// while (tmp)
	// {
	// 	ft_printf("num = %i, index = %i\n", tmp->number, tmp->index);
	// 	tmp = tmp->next;
	// }
	// if (!(is_sorted(stack_a, sorted, 1, stack_a->length)))
	// {
	// 	ft_printf("%i\n", get_pivot(stack_a, sorted, 1, stack_a->length));
	// 	ft_printf("%i\n", pushes_possible(stack_a, pivot, 1));
	// }
	// print_stacks(stack_a, stack_b);
	// quicksort_a(stack_a, stack_b, sorted, stack_a->length);
	// bucketsort(stack_a, stack_b);
	// smallest_alg(stack_a, stack_b);
	// ft_printf("%i\n", get_pivot(stack_a, sorted, 1, stack_a->length));
	// print_stacks(stack_a, stack_b);
	// sort_3_a(stack_a);
	// print_stacks(stack_a, stack_b);

	// print_stacks(stack_a, stack_b);
	// sort_3_b(stack_b);
	// if (is_sorted_b(stack_b, sorted, 3))
	// 	ft_printf("\nB is sorted\n\n");
	quicksort_a(stack_a, stack_b, stack_a->length);
	// print_stacks(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	// atexit(checkLeaks);
	return (0);
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp;
	t_list	**ptr;
	
	if (stack_a)
	{
		ptr = stack_a->head;
		while (*ptr)
		{
			tmp = *ptr;
			*ptr = (*ptr)->next;
			free(tmp);
		}
		free(stack_a->head);
		free(stack_a->tail);
		free(stack_a);
	}
	if (stack_b)
	{
		ptr = stack_b->head;
		while (*ptr)
		{
			tmp = *ptr;
			*ptr = (*ptr)->next;
			free(tmp);
		}
		free(stack_b->head);
		free(stack_b->tail);
		free(stack_b);
	}
}

void	free_input(char **input, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		free(input[i]);
		i++;
	}
	free(input);
}