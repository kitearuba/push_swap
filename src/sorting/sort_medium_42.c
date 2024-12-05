/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:28 by chrrodri          #+#    #+#             */
/*   Updated: 2024/12/05 23:03:51 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:28 by chrrodri          #+#    #+#             */
/*   Updated: 2024/12/05 22:53:41 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_unsorted_points(t_stack *stack)
{
	t_list	*current;
	int		unsorted_points;

	if (!stack || stack->size <= 1)
		return (0); // No unsorted points in a small stack
	current = stack->top;
	unsorted_points = 0;
	while (current && current->next)
	{
		if (*(int *)current->content > *(int *)current->next->content)
			unsorted_points++;
		current = current->next;
	}
	// Check circular condition for edge cases
//	if (*(int *)stack->top->content < *(int *)stack->top->content)
//		unsorted_points++;
	return (unsorted_points);
}


void	sort_medium(t_stack *a, t_stack *b)
{
	// If only a few unsorted points, fix with minimal operations
	if (count_unsorted_points(a) <= 5)
	{
		// Example: Fix small unsorted areas with rotations or swaps
		if (*(int *)a->top->content > *(int *)a->top->next->content)
			sa(a); // Swap top two elements if needed
		else
			ra(a); // Rotate to correct small misalignments
		return ;
	}
	if (a->size <= 10)
	{
		// Step 1: Push smallest elements to B until only 3 elements remain in A
		while (a->size > 3)
			push_smallest_to_b(a, b);
		// Step 2: Sort the remaining 3 elements in A
		sort_three(a);
		// Step 3: Push all elements back from B to A
		while (b->size > 0)
			pa(a, b);  // Push elements from B back to A
	}
	else
	{
		while (b->size <= 10 )
			push_smallest_to_b(a, b);
		sort_three(a);
		while (b->size > 0)
			pa(a, b);  // Push elements from B back to A
	}
}
