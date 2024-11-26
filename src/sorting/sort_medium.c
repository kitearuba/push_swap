/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:28 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/25 18:07:43 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void partition_stack(t_stack *a, t_stack *b, int pivot)
{
    int size = a->size;
    while (size-- > 3)
    {
        if (*(int *)a->top->content <= pivot)
            pb(a, b); // Push smaller elements to B
        else
            ra(a); // Rotate larger elements in A
    }
}

static void reintegrate_stack(t_stack *a, t_stack *b)
{
    int max_index;

    while (b->top)
    {
        max_index = find_max_index(b);

        if (max_index <= b->size / 2)
        {
            while (max_index-- > 0)
                rb(b); // Rotate forward
        }
        else
        {
            while (max_index++ < b->size)
                rrb(b); // Rotate backward
        }
        pa(a, b); // Push max element to A
    }
}

void sort_medium(t_stack *a, t_stack *b)
{
    int pivot;

    if (a->size <= 3)
    {
        sort_small(a, b); // Delegate to small sort for 3 or fewer elements
        return;
    }

    pivot = calculate_median(a); // Find median as the pivot
    partition_stack(a, b, pivot); // Partition stack A into A and B
    sort_small(a, b); // Use sort_small for the 3 remaining elements in A
    reintegrate_stack(a, b); // Push back elements from B to A
}
