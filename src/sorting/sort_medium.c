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

// Bring target element to the top of the stack
static void bring_to_top(t_stack *stack, int target_index)
{
	if (target_index <= stack->size / 2)
		while (target_index-- > 0)
			ra(stack);
	else
		while (target_index++ < stack->size)
			rra(stack);
}

// Push elements in the range [low, high] to Stack B
static void push_chunk_to_b(t_stack *a, t_stack *b, int low, int high)
{
	int target_index;

	while (1)
	{
		target_index = find_target_index(a, low, high);
		if (target_index == -1)
			break;
		bring_to_top(a, target_index);
		pb(a, b);
	}
}

// Push elements back from Stack B to Stack A in sorted order
static void push_back_to_a(t_stack *a, t_stack *b)
{
	int max_index;

	while (b->size > 0)
	{
		max_index = find_max_index(b);
		bring_to_top(b, max_index);
		pa(a, b);
	}
}

// Medium sorting algorithm
void sort_medium(t_stack *a, t_stack *b)
{
	int chunk_size;
	int low;
	int high;
	int num_chunks;
	int i;

	num_chunks = 5; // Adjust for performance
	chunk_size = (find_max(a) - find_min(a) + 1) / num_chunks;
	i = 0;
	while (i < num_chunks)
	{
		low = find_min(a) + i * chunk_size;
		high = low + chunk_size - 1;
		push_chunk_to_b(a, b, low, high);
		i++;
	}
	push_back_to_a(a, b);
}
