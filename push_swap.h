/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 10:45:42 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/16 18:00:10 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

// ---------------------structs--------------------------------
typedef struct s_list
{
	int				number;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;
typedef struct s_stack
{
	t_list	**head;
	t_list	**tail;
	int		length;
	int		round;
}			t_stack;
// -----------------------------------------------------
t_list	*ft_newlst(int number);
void	ft_lstadd_back(t_stack *stack, t_list *new);
void	free_stacks(t_stack *stack_a, t_stack *stack_b);
void	free_input(char **input, int argc);
void	init_a(int argc, char **argv, t_stack *stack_a);
void	init_b(t_stack *stack_b);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
// -----------------------swap------------------------------
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
// -----------------------push------------------------------
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
// -----------------------rotate------------------------------
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
// -----------------------operations------------------------------
void	find_and_push(t_stack *stack_a, t_stack *stack_b, int num);
void	push_and_rotate(t_stack *stack_a, t_stack *stack_b);
// ------------------------algorithms-----------------------------
void    smallest_alg(t_stack *stack_a, t_stack *stack_b);
int     get_median(t_stack *stack);
int 	get_pivot(t_stack *stack, int *sorted, int opt, int len);
int 	pushes_possible(t_stack *stack, int pivot, int opt);
int 	is_sorted(t_stack *stack, int *sorted, int opt, int len);
int 	*selection_sort(t_stack *stack);
void	bucketsort(t_stack *stack_a, t_stack *stack_b);
void    quicksort_a(t_stack *stack_a, t_stack *stack_b, int pushes);
void    quicksort_b(t_stack *stack_a, t_stack *stack_b, int pushes);
int		pivot_a_compare(t_stack *stack_a, t_stack *stack_b, int pushes, int pivot);
int		pivot_b_compare(t_stack *stack_a, t_stack *stack_b, int pushes, int pivot);
void    sort_3(t_stack *stack_a, t_stack *stack_b);
void	sort_2(t_stack *stack_a, t_stack *stack_b);
// ------------------------utils-----------------------------
void    swap_num(int *a, int *b);

#endif