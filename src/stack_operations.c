/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:59:36 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/22 12:16:48 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_stack(void)
{
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack)
    {
        write(2, "Error: Memory allocation failed\n", 32);
        return (NULL);
    }
    stack->top = NULL; // Initially, the stack is empty
    stack->size = 0;   // The size of the stack is zero
    return (stack);
}

void push(t_stack *stack, int value)
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
    {
        write(2, "Error: Memory allocation failed\n", 32);
        return;
    }
    new_node->value = value;   // Assign the number to the new node
    new_node->next = stack->top; // Link the new node to the current top
    stack->top = new_node;     // Update the top of the stack
    stack->size++;             // Increment the size
}

int pop(t_stack *stack)
{
    t_node *temp;
    int value;

    if (!stack->top)
        return (-1);
    temp = stack->top;
    value = temp->value;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return (value);
}
