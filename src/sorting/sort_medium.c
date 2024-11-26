/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:28 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/26 22:02:49 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Helper to perform Insertion Sort
static void insertion_sort(t_stack *a, t_stack *b)
{
    while (a->size > 0)
    {
        push_min_to_b(a, b); // Push smallest element to B
    }
    while (b->size > 0)
    {
        pa(a, b); // Push all back to A
    }
}

// Helper to perform Chunk Sorting
static void chunk_sort(t_stack *a, t_stack *b, int chunk_size)
{
    int i = 0;
    while (a->size > 0)
    {
        int target_value = find_next_target(a, chunk_size, i++);
        move_to_top(a, target_value);
        pb(a, b); // Push elements in the current chunk to B
    }
    while (b->size > 0)
    {
        pa(a, b); // Push back from B to A
    }
}

// Main sorting function for medium-sized inputs
void sort_medium(t_stack *a, t_stack *b)
{
    if (a->size <= 20)
    {
        insertion_sort(a, b);
    }
    else if (a->size <= 100)
    {
        int chunk_size = calculate_chunk_size(a->size);
        chunk_sort(a, b, chunk_size);
    }
}

