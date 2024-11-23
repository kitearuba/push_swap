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

// Helper to push nodes within a value range to Stack B
static void push_chunk_to_b(t_stack *a, t_stack *b, int low, int high)
{
    t_node *current = a->top;
    int index = 0;

    while (index < a->size)
    {
        if (current->value >= low && current->value <= high)
        {
            pb(a, b); // Push to stack B
            current = a->top; // Reset traversal
            index = 0;
        }
        else
        {
            ra(a); // Rotate stack A
            current = a->top;
            index++;
        }
    }
}

void sort_medium(t_stack *a, t_stack *b)
{
    int 	num_chunks;
    int		chunk_size;
    int		low;
    int		high;
    int		i;

    num_chunks = 5; // Adjust based on stack size
    chunk_size = (a->size + num_chunks - 1) / num_chunks; // Ceiling division
    i = 0;
    while (i < num_chunks)
    {
        low = i * chunk_size;
        high = (i + 1) * chunk_size - 1;
        push_chunk_to_b(a, b, low, high); // Push chunk to stack B
        i++;
    }

    // Merge back into stack A
    while (b->top)
        pa(a, b);
}
