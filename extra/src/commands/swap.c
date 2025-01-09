/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:57:55 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/09 11:21:51 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// Swaps the first two elements of the stack.
static void	swap_top_two(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

// Swaps the top two elements of stack a.
void	sa(t_stack **a, int j)
{
	swap_top_two(a);
	if (j == 0)
		write(1, "sa\n", 3);
}

// Swaps the top two elements of stack b.
void	sb(t_stack **b, int j)
{
	swap_top_two(b);
	if (j == 0)
		write(1, "sb\n", 3);
}

// Performs sa and sb simultaneously.
void	ss(t_stack **a, t_stack **b, int j)
{
	swap_top_two(a);
	swap_top_two(b);
	if (j == 0)
		write(1, "ss\n", 3);
}
