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

int	find_closest_target(t_stack *stack, int start, int end)
{
	t_list	*current;
	int		value_top;
	int		index_top;
	current = stack->top;
	value_top = -1;
	index_top = 0;
	while (current)
	{
		if (*(int *)current->content >= start && *(int *)current->content <= end)
		{
			value_top = *(int *)current->content;
			break ;
		}
		index_top++;
		current = current->next;
	}
	return (value_top);
}

void move_to_top(t_stack *stack, int value)
{
    int index;
    int size;

    index = find_index(stack, value); // Find the index of the value
    size = stack->size;

    if (index == -1) // Value not found
        return;

    if (index <= size / 2)
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

static void	sort_chunks(t_stack *a, t_stack *b, int chunk_size)
{
	int	min;
	int	max;
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;
	min = find_min(a);
	max = find_max(a);
	chunk_size = (max - min + 1) / num_chunks;
	chunk_start = min;
	while (num_chunks > 0)
	{
		chunk_end = (num_chunks == 1) ? max : chunk_start + chunk_size - 1;
		while (has_values_in_range(a, chunk_start, chunk_end))
		{
			int target = find_closest_target(a, chunk_start, chunk_end);
			move_to_top(a, target);
			pb(a, b);
		}
		chunk_start = chunk_end + 1;
		num_chunks--;
	}

	/*
	int	start;
	int	end;

	start = find_min(a);
	while (start <= find_max(a))
	{
		end = start + chunk_size -1;
		while
		{
			
		}
	}
	*/
}

void	reintegrate_stack(t_stack *a, t_stack *b)
{
	int	max;
	while (b->size > 0)
	{
		max = find_max(b);
		move_to_top(b, max);
		pa(a, b);
	}
}

// Main sorting function for medium_large-sized inputs
void	sort_medium_large(t_stack *a, t_stack *b)
{
	int	chunck_size;
if

	if (a->size <=50)
		chunk_size = size / 5;else
	else
		chunk_size = size / 10;
	sort_chunks(a, b, chunk_size);
	restore_stack_a(a, b);
}
