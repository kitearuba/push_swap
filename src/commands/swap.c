/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:57:55 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/15 18:18:57 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*   swap_top_two                                                             */
/*                                                                            */
/*   Swaps the first two elements of a stack.                                 */
/*                                                                            */
/*   @param stack: Pointer to the stack.                                      */
/*                                                                            */
/* ************************************************************************** */

static void	swap_top_two(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;

	if (!*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	second_node = (*stack)->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*stack = second_node;
}

/* ************************************************************************** */
/*   sa                                                                       */
/*                                                                            */
/*   Swaps the top two elements of stack A.                                   */
/*                                                                            */
/*   @param a: Pointer to stack A.                                            */
/*   @param j: Flag to control output (0 prints "sa").                        */
/*                                                                            */
/* ************************************************************************** */

void	sa(t_stack **a, int j)
{
	swap_top_two(a);
	if (j == 0)
		write(1, "sa\n", 3);
}

/* ************************************************************************** */
/*   sb                                                                       */
/*                                                                            */
/*   Swaps the top two elements of stack B.                                   */
/*                                                                            */
/*   @param b: Pointer to stack B.                                            */
/*   @param j: Flag to control output (0 prints "sb").                        */
/*                                                                            */
/* ************************************************************************** */

void	sb(t_stack **b, int j)
{
	swap_top_two(b);
	if (j == 0)
		write(1, "sb\n", 3);
}

/* ************************************************************************** */
/*   ss                                                                       */
/*                                                                            */
/*   Swaps the top two elements of both stacks A and B simultaneously.        */
/*                                                                            */
/*   @param a: Pointer to stack A.                                            */
/*   @param b: Pointer to stack B.                                            */
/*   @param j: Flag to control output (0 prints "ss").                        */
/*                                                                            */
/* ************************************************************************** */

void	ss(t_stack **a, t_stack **b, int j)
{
	swap_top_two(a);
	swap_top_two(b);
	if (j == 0)
		write(1, "ss\n", 3);
}
