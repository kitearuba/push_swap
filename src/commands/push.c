/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:57:02 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/12 01:32:00 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*   pa                                                                       */
/*                                                                            */
/*   Pushes the top element of stack B onto stack A.                          */
/*                                                                            */
/*   @param a: Pointer to stack A.                                            */
/*   @param b: Pointer to stack B.                                            */
/*   @param j: Flag to control output (0 prints "pa").                        */
/*                                                                            */
/* ************************************************************************** */
void	pa(t_stack **a, t_stack **b, int j)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = temp;
	if (*b)
		(*b)->prev = NULL;
	(*a)->prev = NULL;
	if (temp)
		temp->prev = *a;
	if (j == 0)
		write(1, "pa\n", 3);
}

/* ************************************************************************** */
/*   pb                                                                       */
/*                                                                            */
/*   Pushes the top element of stack A onto stack B.                          */
/*                                                                            */
/*   @param stack_a: Pointer to stack A.                                      */
/*   @param stack_b: Pointer to stack B.                                      */
/*   @param j: Flag to control output (0 prints "pb").                        */
/*                                                                            */
/* ************************************************************************** */
void	pb(t_stack **stack_a, t_stack **stack_b, int j)
{
	t_stack	*temp;

	if (!*stack_a)
		return ;
	temp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = temp;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	(*stack_b)->prev = NULL;
	if (temp)
		temp->prev = *stack_b;
	if (j == 0)
		write(1, "pb\n", 3);
}