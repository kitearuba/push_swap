/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:59:36 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/24 02:24:01 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_stack(void)
{
	t_stack	 *stack 

	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		fata_error("Failed to create stack", NULL)
        	return (NULL);
	}
	stack->top = NULL; // Initially, the stack is empty
	stack->size = 0;   // The size of the stack is zero
	return (stack);
}

void push(t_stack *stack, int value)
{
	int	*content;
	t_list	*new_node;

	content = malloc (sizeof(int)); // Allocate memory for the value
	if (!content)
		fatal_error("Memory allocation failed", NULL);
	*content = value;
	new_node = ft_lstnew(content); // Create a new list node
	if (!new_node)
	{
		free(content);
		fatal_error("Memory allocation failed", NULL);
	}
	ft_lstadd_front(&(stack->top), new mode);
	stack->size++;
}

int pop(t_stack *stack)
{
	t_list	*tmp;
	int	value;

	if (!stack->top) // Check if stack is empty
		return (-1);
	tmp = stack->top;
	stack->top = stack->top->next; // Update the top to the next element
	value = (int *) tmp->content; // Retrieve the value
	free(tmp->content); // Free the content
	free(tmp); // Free the node
	stack->size--;
	return (*value); // Return the popped value
}
