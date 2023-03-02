/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 10:45:42 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/03/02 15:43:20 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

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
}			t_stack;
t_list	*ft_newlst(int number);
void	ft_lstadd_back(t_stack *stack, t_list *new);
void	init_a(int argc, char **argv, t_stack *stack_a);
void	init_b(t_stack *stack_b);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
void    swap(t_stack *stack_a, t_stack *stack_b, int option);
void    swap_stack(t_stack *stack);
void    push(t_stack *stack_a, t_stack *stack_b, int option);
void    push_stack(t_stack *src, t_stack *dst);
void    rotate(t_stack *stack_a, t_stack *stack_b, int option);
void    rotate_stack(t_stack *stack);
void	rev_rotate(t_stack *stack_a, t_stack *stack_b, int option);
void	rev_rotate_stack(t_stack *stack);
void    smallest_alg(t_stack *stack_a, t_stack *stack_b);

#endif