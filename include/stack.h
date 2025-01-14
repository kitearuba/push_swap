/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:40:42 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/09 11:07:42 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../libft/include/libft.h"

/* ************************************************************************** */
/*                           Stack Structure                                  */
/* ************************************************************************** */


typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;


/* ************************************************************************** */
/*                           Function Prototypes                              */
/* ************************************************************************** */

/* Stack Management */
t_stack	*create_stack(void);
void	free_stack(t_stack *stack);
void	free_all_stacks(t_stack *a, t_stack *b);

/* Stack Operations */
t_stack    *stack_last(t_stack *stack);
int        stack_size(t_stack *stack);
void	stack_free(t_stack **stack);
t_stack	*stack_new(long value);

/* Commands */
void	sa(t_stack **a, int j);
void	sb(t_stack **b, int j);
void	ss(t_stack **a, t_stack **b, int j);
void	pa(t_stack **a, t_stack **b, int j);
void	pb(t_stack **stack_a, t_stack **stack_b, int j);
void	ra(t_stack **a, int j);
void	rb(t_stack **b, int j);
void	rr(t_stack **a, t_stack **b, int j);
void	rra(t_stack **a, int j);
void	rrb(t_stack **b, int j);
void	rrr(t_stack **a, t_stack **b, int j);

#endif // STACK_H