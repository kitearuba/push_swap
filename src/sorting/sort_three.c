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

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                           Sort Three Logic                                 */
/* ************************************************************************** */

/**
 * sort_three - Sorts a stack of exactly three elements.
 * @stack: Pointer to the stack to sort.
 * Description:
 * - Implements sorting using stack operations (sa, ra, rra).
 */
void sort_three(t_stack **stack)
{
    int top;
    int middle;
    int bottom;

    if (!stack || !*stack || !(*stack)->next || !(*stack)->next->next)
        return;

    top = (*stack)->nbr;
    middle = (*stack)->next->nbr;
    bottom = (*stack)->next->next->nbr;

    if (top > middle && middle < bottom && top < bottom)
        sa(stack, 0);
    else if (top > middle && middle > bottom && top > bottom)
    {
        sa(stack, 0);
        rra(stack, 0);
    }
    else if (top > middle && middle < bottom && top > bottom)
        ra(stack, 0);
    else if (top < middle && middle > bottom && top < bottom)
    {
        sa(stack, 0);
        ra(stack, 0);
    }
    else if (top < middle && middle > bottom && top > bottom)
        rra(stack, 0);
}

