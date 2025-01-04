/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:59:37 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/04 22:28:50 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* ************************************************************************** */
/*                           Sort Three Logic                                 */
/* ************************************************************************** */

/**
 * sort_three - Sorts a stack of exactly three elements.
 * @stack: Pointer to the stack to sort.
 * Description:
 * - Implements sorting using stack operations (sa, ra, rra).
 */
void sort_three(t_stack *stack)
{
    int top;
    int middle;
    int bottom;

    top = stack->top->nbr;
    middle = stack->top->next->nbr;
    bottom = stack->top->next->next->nbr;

    if (top > middle && middle < bottom && top < bottom)
        sa(stack);
    else if (top > middle && middle > bottom && top > bottom)
    {
        sa(stack);
        rra(stack);
    }
    else if (top > middle && middle < bottom && top > bottom)
        ra(stack);
    else if (top < middle && middle > bottom && top < bottom)
    {
        sa(stack);
        ra(stack);
    }
    else if (top < middle && middle > bottom && top > bottom)
        rra(stack);
}
