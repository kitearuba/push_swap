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

// Move target element to the top of Stack A
static void bring_to_top(t_stack *stack, int target_index)
{
	if (target_index <= stack->size / 2)
	{
		while (target_index-- > 0)
			ra(stack);
	}
	else
	{
		while (target_index++ < stack->size)
			rra(stack);
	}
}

// Push elements in the range [low, high] to Stack B
static void push_chunk_to_b(t_stack *a, t_stack *b, int low, int high)
{
	int target_index;

	while ((target_index = find_target_index(a, low, high)) != -1)
	{
		bring_to_top(a, target_index); // Bring target to the top of Stack A
		pb(a, b);                     // Push target to Stack B
	}
}

// Push elements back from Stack B to Stack A in sorted order
static void push_back_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		int max_index = find_max_index(b); // Function to find the index of the max element in Stack B
		bring_to_top(b, max_index);       // Bring max element to top of Stack B
		pa(a, b);                         // Push it back to Stack A
	}
}

// Medium sorting algorithm
void sort_medium(t_stack *a, t_stack *b)
{
	int chunk_size;
	int low;
	int high;
	int num_chunks;

	num_chunks = 5; // Adjust based on performance testing
	chunk_size = (find_max(a) - find_min(a) + 1) / num_chunks;

	for (int i = 0; i < num_chunks; i++)
	{
		low = find_min(a) + i * chunk_size;
		high = low + chunk_size - 1;
		push_chunk_to_b(a, b, low, high);
	}

	push_back_to_a(a, b); // Reintegrate elements from Stack B to Stack A
}
