/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 10:56:55 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/02/21 15:28:29 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int		num;
	t_list	*new;

	stack_a->head = (t_list **) malloc(sizeof(t_list *));
	if (!stack_a->head)
		exit(0);
	stack_a->tail = (t_list **) malloc(sizeof(t_list *));
	if (!stack_a->tail)
		exit(0);
	stack_b->tail = (t_list **) malloc(sizeof(t_list *));
	if (!stack_b->tail)
		exit(0);
	stack_b->head = (t_list **) malloc(sizeof(t_list *));
	if (!stack_b->head)
		exit(0);
	*(stack_a->head) = NULL;
	*(stack_b->head) = NULL;
	stack_a->length = argc - 1;
	stack_b->length = 0;
	while (argc > 1)
	{
		num = atoi(argv[argc - 1]);
		new = ft_newlst(num);
		ft_lstadd_back(stack_a, new);
		argc--;
	}
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if ((*stack_a->head) && (*stack_a->tail))
		printf("head stack a: %i\ntail stack a: %i\n", (*stack_a->head)->number, (*stack_a->tail)->number);
	printf("stack a:	");
	while (*stack_a->tail != NULL)
	{
		printf("%i ", (*stack_a->tail)->number);
		*stack_a->tail = (*stack_a->tail)->prev;
	}
	if ((*stack_b->head) && (*stack_b->tail))
		printf("head stack a: %i\ntail stack a: %i\n", (*stack_b->head)->number, (*stack_b->tail)->number);
	printf("\nstack b:	");
	while (*stack_b->head != NULL)
	{
		printf("%i ", (*stack_b->head)->number);
		*stack_b->head = (*stack_b->head)->next;
	}	
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
	init(argc, argv, stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
}
