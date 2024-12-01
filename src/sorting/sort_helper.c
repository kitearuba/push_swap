/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:23:20 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/27 17:46:44 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
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
void	push_min_to_b(t_stack *a, t_stack *b)
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
*/
/**
 * has_values_in_range - Check if the stack has elements in the given range.
 * @stack: The stack to check.
 * @start: The lower bound of the range.
 * @end: The upper bound of the range.
 *
 * Return: 1 if there are values in the range, otherwise 0.
 */
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

/**
 * reintegrate_stack - Reintegrate elements from stack B back to stack A in descending order.
 * @a: The destination stack (A).
 * @b: The source stack (B).
 *
 * Description:
 * This function moves all elements from stack B to stack A while maintaining
 * the descending order in stack A. It assumes that elements in stack B are already
 * pushed in chunks (sorted chunks or grouped values). The function uses `find_max`
 * and `move_to_top` to locate and position the maximum value in stack B at the top,
 * then pushes it to stack A using `pa`.
 */

#include "push_swap.h"

// Function to check if a stack is sorted in ascending order
int	is_sorted(t_stack *stack)
{
	t_list	*current;

	if (!stack || !stack->top)
		return (1); // An empty stack is considered sorted

	current = stack->top;
	while (current && current->next)
	{
		if (*(int *)current->content > *(int *)current->next->content)
			return (0); // Found an unsorted pair
		current = current->next;
	}
	return (1); // Stack is sorted
}

void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min;
	int	index;

	min = find_min(a);
	index = find_index(a, min);

	if (index <= a->size / 2)
	{
		while (*(int *)a->top->content != min)
			ra(a); // Rotate forward if the element is closer to the top
	}
	else
	{
		while (*(int *)a->top->content != min)
			rra(a); // Reverse rotate if the element is closer to the bottom
	}
	pb(a, b); // Push the smallest element to stack B
}


void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = find_index(a, find_min(a));
	if (min_index <= a->size / 2)
	{
		while (min_index > 0)
		{
			ra(a);
			min_index--;
		}
	}
	else
	{
		while (min_index < a->size)
		{
			rra(a);
			min_index++;
		}
	}
	pb(a, b);
}