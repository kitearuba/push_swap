/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:40:42 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/24 21:21:01 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

/* ************************************************************************** */
/*                               Includes                                     */
/* ************************************************************************** */

# include "../libft/include/libft.h"

/* ************************************************************************** */
/*                           Stack Structure                                  */
/* ************************************************************************** */

/**
 * struct s_stack - Represents a stack for push_swap.
 * @top: Pointer to the top element (linked list).
 * @size: Number of elements in the stack.
 */
typedef struct s_stack
{
	t_list	*top;
	int		size;
}	t_stack;

/* ************************************************************************** */
/*                           Function Prototypes                              */
/* ************************************************************************** */

/* Stack Management */
t_stack	*create_stack(void);
void	free_stack(t_stack *stack);
void	free_all_stacks(t_stack *a, t_stack *b);

/* Stack Operations */
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	swap_top_two(t_stack *stack);
void	push_node(t_stack *from, t_stack *to);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

/* Commands */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif // STACK_H
