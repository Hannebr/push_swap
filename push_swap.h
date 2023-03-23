/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 10:45:42 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/23 15:54:10 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

// ---------------------structs--------------------------------
typedef struct s_list
{
	int				number;
	int				index;
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
void	assign_index(t_stack *stack);
// -----------------------parse------------------------------
char 	**parse_input(int *argc, char **argv);
char	**trim_input(char **argv, int argc);
int 	is_valid_input(char **input, int argc);
int		is_valid_int(char *str);
int		has_duplicates(t_stack *stack);
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
// -----------------------check------------------------------
int 	is_sorted_a(t_stack *stack_a, int len);
int		is_sorted_b(t_stack *stack_b, int len);
int		pushes_possible(t_stack *stack, int pivot, int opt);
// ------------------------algorithms-----------------------------
void	smallest_alg(t_stack *stack_a, t_stack *stack_b);
int		get_pivot_a(t_stack *stack, int len);
int		get_pivot_b(t_stack *stack);
int		*selection_sort(t_stack *stack);
void	bucketsort(t_stack *stack_a, t_stack *stack_b);
void    quicksort_a(t_stack *stack_a, t_stack *stack_b, int len);
void    quicksort_b(t_stack *stack_a, t_stack *stack_b, int len);
void	push_pivot_a(t_stack *stack_a, t_stack *stack_b, int pivot);
void	push_pivot_b(t_stack *stack_a, t_stack *stack_b, int pivot, int len);
void	placement_a(t_stack *stack_a, t_stack *stack_b, int len);
void	placement_b(t_stack *stack_a, t_stack *stack_b);
int		pivot_a_compare(t_stack *stack_a, t_stack *stack_b, \
int pushes, int pivot);
int		pivot_b_compare(t_stack *stack_a, t_stack *stack_b, \
int pushes, int pivot);
void	sort_3_a(t_stack *stack_a);
void	sort_3_b(t_stack *stack_b);
void	sort_2_a(t_stack *stack_a);
void	sort_2_b(t_stack *stack_b);
// ------------------------utils-----------------------------
void	swap_num(int *a, int *b);

#endif