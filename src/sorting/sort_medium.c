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

// Main sorting function for medium-sized inputs
void sort_medium(t_stack *a, t_stack *b)
{
    while (a->size > 0)
        push_min_to_b(a, b); // Push smallest element to B
    while (b->size > 0)
        pa(a, b); // Push all back to A
}

/*
void	sort_medium(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	current_min;
	int	current_max;

	chunk_size = a->size / 10; // Divide into smaller chunks
	current_min = find_min(a);

	while (has_values_in_range(a, current_min, current_min + chunk_size))
	{
		current_max = current_min + chunk_size;

		while (has_values_in_range(a, current_min, current_max))
		{
			if (*(int *)a->top->content >= current_min &&
			    *(int *)a->top->content <= current_max)
				pb(a, b); // Push elements within range to B
			else
				ra(a); // Rotate A to find elements in range
		}
		current_min = current_max + 1;
	}

	while (b->size > 0)
		pa(a, b); // Push all back from B to A
}

#include "push_swap.h"

void	sort_medium(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	current_min;
	int	current_max;

	chunk_size = a->size / 10; // Divide into smaller chunks

	while (1)
	{
		current_min = find_min(a);
		while (has_values_in_range(a, current_min, current_min + chunk_size))
		{
			current_max = current_min + chunk_size;
			while (has_values_in_range(a, current_min, current_max))
			{
				if (*(int *)a->top->content >= current_min &&
					*(int *)a->top->content <= current_max)
					pb(a, b); // Push elements within range to B
				else
					ra(a); // Rotate A to find elements in range
			}
			current_min = current_max + 1;
		}
		while (b->size > 0)
			pa(a, b); // Push all back from B to A

		// Check if stack 'a' is sorted
		if (is_sorted(a))
			break;

		// If not sorted, repeat the process
	}
}
*/