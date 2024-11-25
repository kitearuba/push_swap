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

// Sort 3 elements
static void	sort_three(t_stack *a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = a->top;
	second = first->next;
	third = second->next;
	if (*(int *)first->content > *(int *)second->content)
	{
		sa(a);
	}
	if (*(int *)first->content > *(int *)third->content)
	{
		rra(a);
	}
	if (*(int *)second->content > *(int *)third->content)
	{
		sa(a);
		ra(a);
	}
}

// Find and push the smallest element to stack B
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
	// Rotate to the smallest element
	while (min_index-- > 0)
		ra(a);
	pb(a, b); // Push the smallest element to B
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
		sort_three(a); //Sort remaining 3 elements
		while (b->top)
			pa(a, b); // Push back from B to A
	}
}
