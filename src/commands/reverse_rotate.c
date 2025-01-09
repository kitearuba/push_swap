/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:04:56 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/25 20:29:05 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// Moves the last element to the front of the stack.
static void reverse_rotate_stack(t_stack **stack)
{
	t_stack *tmp, *prev;

	if (!*stack || !(*stack)->next)
		return;
	tmp = *stack;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

// Reverse rotates stack a.
void rra(t_stack **a, int j)
{
	reverse_rotate_stack(a);
	if (j == 0)
		write(1, "rra\n", 4);
}

// Reverse rotates stack b.
void rrb(t_stack **b, int j)
{
	reverse_rotate_stack(b);
	if (j == 0)
		write(1, "rrb\n", 4);
}

// Reverse rotates both stacks a and b simultaneously.
void rrr(t_stack **a, t_stack **b, int j)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	if (j == 0)
		write(1, "rrr\n", 4);
}
