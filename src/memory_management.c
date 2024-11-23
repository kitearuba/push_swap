/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:48 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/22 12:05:53 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Free all nodes in the stack and the stack itself.
 */
void free_stack(t_stack *stack)
{
    t_node *temp;

    while (stack->top)
    {
        temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    free(stack);
}

/**
 * Free multiple stacks, handling NULL safely.
 */
void free_all_stacks(t_stack *a, t_stack *b)
{
    if (a)
        free_stack(a);
    if (b)
        free_stack(b);
}