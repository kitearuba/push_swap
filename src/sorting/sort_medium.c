/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:28 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/27 18:37:58 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
// Main sorting function for medium-sized inputs
void sort_medium(t_stack *a, t_stack *b)
{
  if (a->size <= 10)
    while (a->size > 0)
        push_min_to_b(a, b); // Push smallest element to B
    while (b->size > 0)
        pa(a, b); // Push all back to A

}


void	sort_medium(t_stack *a, t_stack *b)
{
	// Step 1: Push smallest elements to B until only 3 elements remain in A
	while (a->size > 3)
	push_smallest_to_b(a, b);

	// Step 2: Sort the remaining 3 elements in A
	sort_three(a);

	// Step 3: Push all elements back from B to A
	while (b->size > 0)
		pa(a, b);  // Push elements from B back to A

	// Ensure A is fully sorted (final adjustment)
	//while (!is_sorted(a))
	//-*	ra(a);
}
*/

#include "push_swap.h"

int	has_values_in_range(t_stack *stack, int start, int end)
{
	t_list	*current;

	current = stack->top;
	while (current)
	{
		if (*(int *)current->content >= start && *(int *)current->content <= end)
			return (1);
		current = current->next;
	}
	return (0);
}

int	find_closest_target(t_stack *stack, int start, int end)
{
	t_list	*current;
	int		closest_value;

	if (!stack || !stack->top)
		return (-1); // Return an invalid value for empty stack

	current = stack->top;
	closest_value = -1;

	while (current)
	{
		int value = *(int *)current->content;

		// Check if value is within range
		if (value >= start && value <= end)
		{
			// If no closest_value is set yet, assign it
			if (closest_value == -1)
				closest_value = value;

			// If current value is "closer" to the top (smaller in magnitude), update closest_value
			else if (abs(*(int *)stack->top->content - value) <
			         abs(*(int *)stack->top->content - closest_value))
				closest_value = value;
		}
		current = current->next;
	}
	return (closest_value); // Return the closest value found, or -1 if none
}

/**
 * Pushes the closest element in a range to the top of stack `a` and then to stack `b`.
 * This minimizes rotations and ensures efficient chunk processing.
 */
void push_closest_to_b(t_stack *a, t_stack *b, int start, int end)
{
    int top_index = find_closest_target(a, start, end);
    if (top_index == -1)
        return;
    move_to_top(a, top_index); // Bring the closest target to the top of stack `a`
    pb(a, b); // Push to stack `b`
}

/**
 * Reintegrates all elements from stack `b` back to stack `a` in descending order.
 */
void reintegrate_from_b(t_stack *a, t_stack *b)
{
    while (b->size > 0)
    {
        int max_index = find_max(b); // Find the max value in stack `b`
        move_to_top(b, max_index);  // Bring max to the top of stack `b`
        pa(a, b);                   // Push max back to stack `a`
    }
}

/**
 * Main sorting function for medium-sized stacks (up to ~40 elements).
 */
void sort_medium(t_stack *a, t_stack *b)
{
    int chunk_size = a->size / 4; // Divide into 4 chunks
    int i;

    if (chunk_size < 1)
        chunk_size = 1;

    // Map values to normalized indices for easier chunking
    map_to_indexes(a);

    // Push elements to `b` chunk by chunk
    for (i = 0; i < a->size; i += chunk_size)
    {
        int start = i;
        int end = i + chunk_size - 1;
        if (end >= a->size)
            end = a->size - 1;

        while (has_values_in_range(a, start, end))
            push_closest_to_b(a, b, start, end);
    }

    // Reintegrate elements back from `b` to `a`
    reintegrate_from_b(a, b);
}
