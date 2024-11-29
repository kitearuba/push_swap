/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_large.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:15:04 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/27 22:14:37 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * find_closest_target - Find the closest value in the given range.
 * @stack: The stack to search.
 * @start: The lower bound of the range.
 * @end: The upper bound of the range.
 *
 * Return: The value of the closest element in the range.
 */
int	find_closest_target(t_stack *stack, int start, int end)
{
	t_list	*current;
	int		value_top;

	current = stack->top;
	value_top = -1;
	while (current)
	{
		if (*(int *)current->content >= start && *(int *)current->content <= end)
		{
			value_top = *(int *)current->content;
			break ;
		}
		current = current->next;
	}
	return (value_top);
}

/**
 * move_to_top - Move a specific value to the top of the stack.
 * @stack: The stack to operate on.
 * @value: The value to move to the top.
 */
void move_to_top(t_stack *stack, int value)
{
    int index;

    index = find_index(stack, value); // Find the index of the value
    if (index == -1) // Value not found
        return ;
    if (index <= stack->size / 2)
    {
        while (*(int *)stack->top->content != value)
            ra(stack); // Rotate stack upwards
    }
    else
    {
        while (*(int *)stack->top->content != value)
            rra(stack); // Rotate stack downwards
    }
}


/**
 * sort_chunks - Sort the stack by dividing it into chunks and pushing to stack B.
 * @a: The source stack (A).
 * @b: The destination stack (B).
 * @chunk_size: Size of each chunk.
 */
static void	sort_chunks(t_stack *a, t_stack *b, int num_chunks)
{
	int	chunk_size;
	int	min;
	int	max;
	int	start;
	int	end;

	min = find_min(a);
	max = find_max(a);
	chunk_size = (max - min + 1) / num_chunks;
	start = min;

	while (num_chunks > 0)
	{
		// Determine the end of the current chunk
		if (num_chunks == 1)
			end = max;
		else
			end = start + chunk_size - 1;
		while (find_closest_target(a, start, end) != -1)
		{
			int target = find_closest_target(a, start, end);
			move_to_top(a, target);
			pb(a, b);
		}
		// Sort the current chunk in stack B before processing the next chunk
		if (b->size <= 5)
			sort_small(a, b); // Use the small sort logic for chunks of 5 or fewer
		else
			sort_medium(a, b); // Use the medium sort logic for chunks up to 20
		start = end + 1;
		num_chunks--;
	}
}

/**
 * reintegrate_stack - Reintegrate elements from stack B to stack A in sorted order.
 * @a: The destination stack (A).
 * @b: The source stack (B).
 */

void	reintegrate_stack(t_stack *a, t_stack *b)
{
    while (b->size > 0)
    {
        int max_value = find_max(b); // Find the largest value in stack B
        move_to_top(b, max_value);  // Move it to the top of stack B
        pa(a, b);                   // Push it back to stack A
    }
}

/**
 * sort_medium_large - Sort stacks with size between 21 and 100.
 * @a: The source stack (A).
 * @b: The destination stack (B).
 */
/*
void	sort_medium_large(t_stack *a, t_stack *b)
{
		int	chunk_size;

	if (!a || a->size <= 0)
		return;

	while (!is_sorted(a))
	{
		// Determine chunk size based on the size of the stack
		if (a->size <= 50)
			chunk_size = a->size / 5;
		else if (a->size <= 100)
			chunk_size = a->size / 10;
		// Perform chunk-based sorting
		sort_chunks(a, b, chunk_size);

		// Reintegrate stack B back into stack A
		reintegrate_stack(a, b);

		// If stack A is still not sorted, the loop will repeat
	}
}
*/

#include "push_swap.h"

void	sort_medium_large(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	progress_check = 0;

	if (!a || a->size <= 0)
		return;

	while (!is_sorted(a))
	{
		// Limit the number of iterations to avoid infinite loop
		if (progress_check++ > 1000)
		{
			ft_putstr_fd("Error: Sorting stalled\n", 2);
			return;
		}

		// Determine chunk size
		if (a->size <= 50)
			chunk_size = a->size / 5;
		else if (a->size <= 100)
			chunk_size = a->size / 10;
		else
			chunk_size = a->size / 20;

		// Sort chunks
		sort_chunks(a, b, chunk_size);

		// Reintegrate stack B back to stack A
		reintegrate_stack(a, b);
	}
}