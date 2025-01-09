/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:17 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/09 22:37:42 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * stack_free - Frees all nodes in a stack and sets the pointer to NULL.
 * @stack: Double pointer to the stack to be freed.
 */
void stack_free(t_stack **stack)
{
	t_stack *current;
	t_stack *next;

	if (!stack || !*stack)
		return;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL; // Avoid dangling pointer
}