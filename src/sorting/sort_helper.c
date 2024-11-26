/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:23:20 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/26 22:03:14 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculate chunk size dynamically
int calculate_chunk_size(int size)
{
    if (size <= 50)
        return 5; // Smaller chunks for smaller inputs
    else
        return 10; // Larger chunks for larger inputs
}

// Find the next target value in the current chunk
int find_next_target(t_stack *a, int chunk_size, int index)
{
    t_list *current = a->top;
    int min = find_min(a);
    int max = find_min(a) + chunk_size * (index + 1);

    while (current)
    {
        int value = *(int *)current->content;
        if (value >= min && value <= max)
            return value;
        current = current->next;
    }
    return min; // Fallback to the minimum if no value is found
}

// Move target value to the top of the stack
void move_to_top(t_stack *a, int value)
{
    int index = find_index(a, value);
    if (index < a->size / 2)
    {
        while (*(int *)a->top->content != value)
            ra(a); // Rotate stack to bring target to top
    }
    else
    {
        while (*(int *)a->top->content != value)
            rra(a); // Reverse rotate to bring target to top
    }
}

