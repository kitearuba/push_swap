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

void	sort_medium(t_stack *a, t_stack *b)
{
	// Step 1: Push smallest elements to B until only 3 elements remain in A
	while (a->size > 3)
	{
		int min_value = find_min(a);  // Find the smallest number in A
		move_to_top(a, min_value);   // Rotate A until the smallest number is on top
		pb(a, b);                    // Push the smallest number to B
	}

	// Step 2: Sort the remaining 3 elements in A
	sort_three(a);

	// Step 3: Push all elements back from B to A
	while (b->size > 0)
		pa(a, b);  // Push elements from B back to A

	// Ensure A is fully sorted (final adjustment)
	//while (!is_sorted(a))
	//	ra(a);
}