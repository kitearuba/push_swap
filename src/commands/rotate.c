/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:57:21 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/15 18:18:14 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*   rotate_stack                                                             */
/*                                                                            */
/*   Moves the first element of the stack to the end.                         */
/*                                                                            */
/*   @param stack: Pointer to the stack to rotate.                            */
/*                                                                            */
/* ************************************************************************** */

static void	rotate_stack(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	first_node->next = NULL;
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = first_node;
	first_node->prev = last_node;
}

/* ************************************************************************** */
/*   ra                                                                       */
/*                                                                            */
/*   Rotates stack A.                                                         */
/*   @param a: Pointer to stack A.                                            */
/*   @param j: Flag to control output (0 prints "ra").                        */
/*                                                                            */
/* ************************************************************************** */

void	ra(t_stack **a, int j)
{
	rotate_stack(a);
	if (j == 0)
		write(1, "ra\n", 3);
}

/* ************************************************************************** */
/*   rb                                                                       */
/*                                                                            */
/*   Rotates stack B.                                                         */
/*   @param b: Pointer to stack B.                                            */
/*   @param j: Flag to control output (0 prints "rb").                        */
/*                                                                            */
/* ************************************************************************** */

void	rb(t_stack **b, int j)
{
	rotate_stack(b);
	if (j == 0)
		write(1, "rb\n", 3);
}

/* ************************************************************************** */
/*   rr                                                                       */
/*                                                                            */
/*   Rotates both stack A and stack B simultaneously.                         */
/*   @param a: Pointer to stack A.                                            */
/*   @param b: Pointer to stack B.                                            */
/*   @param j: Flag to control output (0 prints "rr").                        */
/*                                                                            */
/* ************************************************************************** */

void	rr(t_stack **a, t_stack **b, int j)
{
	rotate_stack(a);
	rotate_stack(b);
	if (j == 0)
		write(1, "rr\n", 3);
}
