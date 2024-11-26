/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:37 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/25 22:23:23 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotate optimally to the smallest element
static void	rotate_to_min(t_stack *a, int min_index)
{
	if (min_index <= a->size / 2)
	{
		while (min_index-- > 0)
			ra(a); // Rotate upwards
	}
	else
	{
		min_index = a->size - min_index;
		while (min_index-- > 0)
			rra(a); // Rotate downwards
	}
}

// Push the smallest element to stack B
static void	push_min_to_b(t_stack *a, t_stack *b)
{
	t_list	*current;
	t_list	*min;
	int		index;
	int		min_index;

	current = a->top;
	min = current;
	index = 0;
	min_index = 0;
	while (current)
	{
		if (*(int *)current->content < *(int *)min->content)
		{
			min = current;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	rotate_to_min(a, min_index);
	pb(a, b); // Push the smallest element to B
}

// Optimized sort_three function
void	sort_three(t_stack *a)
{
	int		first;
	int		second;
	int		third;

	first = *(int *)a->top->content;
	second = *(int *)a->top->next->content;
	third = *(int *)a->top->next->next->content;

	if (first > second && second > third)
	{
		// Case: 3 2 1
		sa(a);
		rra(a);
	}
	else if (first > third && third > second)
		ra(a); // Case: 3 1 2
	else if (second > first && first > third)
		rra(a); // Case: 2 3 1
	else if (second > third && third > first)
	{
		// Case: 1 3 2
		sa(a);
		ra(a);
	}
	else if (third > first && first > second)
		sa(a); // Case: 2 1 3
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2 && *(int *)a->top->content > *(int *)a->top->next->content)
		sa(a); // Sort 2 elements
	else if (a->size == 3)
		sort_three(a); // Sort 3 elements
	else
	{
		while (a->size > 3)
			push_min_to_b(a, b); // Push smallest to B
		sort_three(a); // Sort remaining 3 elements
		while (b->top)
			pa(a, b); // Push back from B to A
	}
}
