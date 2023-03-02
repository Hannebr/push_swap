/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 10:56:55 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/02 16:16:49 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_a(int argc, char **argv, t_stack *stack_a)
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
	while (argc > 1)
	{
		num = atoi(argv[argc - 1]);
		new = ft_newlst(num);
		ft_lstadd_back(stack_a, new);
		argc--;
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
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*ptr;
	
	printf("\nstack a:	");
	if (*stack_a->tail)
	{
		ptr = *stack_a->tail;
		while (ptr != NULL)
		{
			printf("%i ", (ptr)->number);
			ptr = (ptr)->prev;
		}
	}
	// if ((*stack_a->head) && (*stack_a->tail))
	// 	printf("\nhead stack a: %i\ntail stack a: %i", (*stack_a->head)->number, (*stack_a->tail)->number);
	printf("\nstack b:	");
	if (*stack_b->tail)
	{
		ptr = *stack_b->tail;
		while (ptr != NULL)
		{
			printf("%i ", (ptr)->number);
			ptr = (ptr)->prev;
		}	
	}
	printf("\n\n");
	// if ((*stack_b->head) && (*stack_b->tail))
	// 	printf("\nhead stack a: %i\ntail stack a: %i\n", (*stack_b->head)->number, (*stack_b->tail)->number);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *) malloc(sizeof(t_stack));
	if (!stack_a)
		exit(0);
	stack_b = (t_stack *) malloc(sizeof(t_stack));
	if (!stack_b)
		exit(0);
	init_a(argc, argv, stack_a);
	init_b(stack_b);
	print_stacks(stack_a, stack_b);
	smallest_alg(stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
}
