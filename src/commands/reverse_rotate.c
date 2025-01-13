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

/* ************************************************************************** */
/*   reverse_rotate_stack                                                     */
/*                                                                            */
/*   Moves the last element of the stack to the front.                        */
/*                                                                            */
/*   @param stack: Pointer to the stack to reverse rotate.                    */
/*                                                                            */
/* ************************************************************************** */

static void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*second_last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = *stack;
	while (last_node->next)
	{
		second_last_node = last_node;
		last_node = last_node->next;
	}
	second_last_node->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	(*stack)->prev = last_node;
	*stack = last_node;
}

/* ************************************************************************** */
/*   rra                                                                      */
/*                                                                            */
/*   Reverse rotates stack A.                                                 */
/*   @param a: Pointer to stack A.                                            */
/*   @param j: Flag to control output (0 prints "rra").                       */
/*                                                                            */
/* ************************************************************************** */

void	rra(t_stack **a, int j)
{
	reverse_rotate_stack(a);
	if (j == 0)
		write(1, "rra\n", 4);
}

/* ************************************************************************** */
/*   rrb                                                                      */
/*                                                                            */
/*   Reverse rotates stack B.                                                 */
/*   @param b: Pointer to stack B.                                            */
/*   @param j: Flag to control output (0 prints "rrb").                       */
/*                                                                            */
/* ************************************************************************** */

void	rrb(t_stack **b, int j)
{
	reverse_rotate_stack(b);
	if (j == 0)
		write(1, "rrb\n", 4);
}

/* ************************************************************************** */
/*   rrr                                                                      */
/*                                                                            */
/*   Reverse rotates both stack A and stack B simultaneously.                 */
/*   @param a: Pointer to stack A.                                            */
/*   @param b: Pointer to stack B.                                            */
/*   @param j: Flag to control output (0 prints "rrr").                       */
/*                                                                            */
/* ************************************************************************** */

void	rrr(t_stack **a, t_stack **b, int j)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	if (j == 0)
		write(1, "rrr\n", 4);
}