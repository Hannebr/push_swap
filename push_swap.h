/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 10:45:42 by hbrouwer      #+#    #+#                 */
/*   Updated: 2023/02/21 14:30:46 by hbrouwer      ########   odam.nl         */
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
void	init(int argc, char **argv, t_stack *stack_a, t_stack *stack_b);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);

#endif