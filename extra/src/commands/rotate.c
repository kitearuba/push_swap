/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:57:21 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/09 11:20:20 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// Moves the first element to the end of the stack.
static void	rotate_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = tmp;
}

// Rotates stack a.
void	ra(t_stack **a, int j)
{
	rotate_stack(a);
	if (j == 0)
		write(1, "ra\n", 3);
}

// Rotates stack b.
void	rb(t_stack **b, int j)
{
	rotate_stack(b);
	if (j == 0)
		write(1, "rb\n", 3);
}

// Rotates both stacks a and b simultaneously.
void	rr(t_stack **a, t_stack **b, int j)
{
	rotate_stack(a);
	rotate_stack(b);
	if (j == 0)
		write(1, "rr\n", 3);
}
