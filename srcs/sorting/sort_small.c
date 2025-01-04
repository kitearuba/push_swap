/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:37 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/04 22:24:44 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * push_smallest_to_b - Moves the smallest element from stack A to stack B.
 * @a: Pointer to stack A.
 * @b: Pointer to stack B.
 * Description:
 * - Finds the index of the smallest element in stack A.
 * - Moves the smallest element to the top of stack A.
 * - Pushes it to stack B.
 */
static void push_smallest_to_b(t_stack *a, t_stack *b)
{
    int min_index;

    min_index = find_min_index(a);
    move_to_top(a, min_index);
    pb(a, b);
}

/**
 * sort_small - Sorts stacks of up to five elements.
 * @a: Pointer to stack A.
 * @b: Pointer to stack B (used as auxiliary stack).
 * Description:
 * - For three elements, calls sort_three.
 * - For more than three elements, moves the smallest element(s) to stack B,
 *   then sorts the remaining elements using sort_three and pushes back.
 */
void sort_small(t_stack *a, t_stack *b)
{
    if (a->size == 2 && a->top->nbr > a->top->next->nbr)
        sa(a);
    else if (a->size == 3)
        sort_three(a);
    else
    {
        while (a->size > 3)
            push_smallest_to_b(a, b);
        sort_three(a);
        while (b->size > 0)
            pa(a, b);
    }
}
