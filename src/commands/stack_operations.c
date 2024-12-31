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
 * Create a new, empty stack.
 */
t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		fatal_error("Failed to create stack", NULL);
		return (NULL);
	}
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

/**
 * Push a value onto the stack.
 */
void	push(t_stack *stack, int value)
{
	int		*content;
	t_list	*new_node;

	content = malloc(sizeof(int));
	if (!content)
		fatal_error("Memory allocation failed", NULL);
	*content = value;
	new_node = ft_lstnew(content);
	if (!new_node)
	{
		free(content);
		fatal_error("Memory allocation failed", NULL);
	}
	ft_lstadd_front(&(stack->top), new_node);
	stack->size++;
}

/**
 * Pop a value from the stack and return it.
 */
int	pop(t_stack *stack)
{
	t_list	*tmp;
	int		*value;

	if (!stack->top)
		return (-1);
	tmp = stack->top;
	stack->top = stack->top->next;
	value = (int *)tmp->content;
	free(tmp->content);
	free(tmp);
	stack->size--;
	return (*value);
}
