/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:59:36 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/24 21:09:18 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Push a value onto the stack.
 * This is now compatible with the `t_stack` structure.
 */
void push(t_stack **stack, long value, long index)
{
	t_stack *new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		fatal_error();
	new_node->nbr = value;
	new_node->index = index;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * Pop a value from the stack and return the node.
 */
t_stack *pop(t_stack **stack)
{
	t_stack *top_node;

	if (!*stack)
		return (NULL);
	top_node = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	return (top_node);
}
