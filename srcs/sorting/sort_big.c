/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:17 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/04 22:37:42 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                         Turkish Sort - Large Sort                          */
/* ************************************************************************** */

/**
 * sort_stack_b - Sorts stack B while elements are being pushed.
 * @a: Pointer to stack A.
 * @b: Pointer to stack B.
 * Description:
 * - Determines the optimal position for each element in stack B.
 * - Applies rotation and push operations to maintain order.
 */
static void sort_stack_b(t_stack *a, t_stack *b)
{
    while (a->size > 3)
    {
        if (is_min_or_max(a, b))
        {
            pb(a, b);
            if (b->size > 1 && b->top->nbr < b->top->next->nbr)
                sb(b);
        }
        else
            rotate_and_push(a, b);
    }
}

/**
 * finalize_stack_a - Rotates stack A to ensure the smallest element is on top.
 * @a: Pointer to stack A.
 */
static void finalize_stack_a(t_stack *a)
{
    int min_index;

    min_index = find_min_index(a);
    move_to_top(a, min_index);
}

/**
 * sort_big - Implements Turkish sort for large stacks.
 * @a: Pointer to stack A.
 * @b: Pointer to stack B (auxiliary stack).
 * Description:
 * - Splits stack A, sorts elements in stack B while pushing.
 * - Rebuilds stack A by pushing elements back from stack B.
 * - Finalizes stack A by ensuring the smallest element is on top.
 */
void sort_big(t_stack *a, t_stack *b)
{
    sort_stack_b(a, b);
    sort_small(a, b);
    while (b->size > 0)
        pa(a, b);
    finalize_stack_a(a);
}
