/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:17 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/11 01:18:42 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*   stack_free                                                               */
/*                                                                            */
/*   Frees all nodes in a stack and sets the stack pointer to NULL.           */
/*                                                                            */
/* ************************************************************************** */

void stack_free(t_stack **stack)
{
	t_stack *current;

	if (!stack || !*stack)
		return ;

	while (stack && *stack)
	{
		current = (*stack)->next; // Clear the next pointer (optional)
		(*stack)->nbr = 0;
		free(*stack);
		*stack = current;
	}
	*stack = NULL; // Ensure the stack pointer is set to NULL
}