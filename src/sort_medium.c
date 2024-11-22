/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:28 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/22 11:56:31 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Helper to find the chunk range
static int get_chunk_size(int total, int num_chunks)
{
    return (total + num_chunks - 1) / num_chunks; // Ceiling division
}

// Push numbers of a chunk to stack B
static void push_chunk_to_b(t_stack *a, t_stack *b, int low, int high)
{
    int i = 0;
    while (i <= a->top)
    {
        if (a->arr[a->top] >= low && a->arr[a->top] <= high)
        {
            pb(a, b);
            i = 0; // Restart to recheck the stack
        }
        else
        {
            ra(a);
            i++;
        }
    }
}

void sort_medium(t_stack *a, t_stack *b)
{
    int num_chunks = 5; // Adjust based on input size
    int chunk_size = get_chunk_size(a->size, num_chunks);
    int low, high;

    for (int i = 0; i < num_chunks; i++)
    {
        low = i * chunk_size;
        high = (i + 1) * chunk_size - 1;
        push_chunk_to_b(a, b, low, high);
    }

    // Merge sorted chunks back to A
    while (b->top >= 0)
        pa(a, b);
}
