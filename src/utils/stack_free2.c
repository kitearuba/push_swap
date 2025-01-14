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
	t_stack *next;

	if (!stack || !*stack)
		return;
	current = *stack;
	while (current)
	{
		next = current->next; // Save the next node
		current->next = NULL; // Clear the next pointer (optional)
		current->prev = NULL; // Clear the prev pointer (optional)
		free(current);        // Free the current node
		current = next;       // Move to the next node
	}
	*stack = NULL; // Ensure the stack pointer is set to NULL
}