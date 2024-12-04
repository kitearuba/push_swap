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

int	count_bits(int max)
{
	int bits;

	bits = 0;
	while (max > 0)
	{
		max /= 2;
		bits++;
	}
	return (bits);
}

// Bubble Sort: Sorts an array in ascending order
void bubble_sort(int *arr, int size)
{
    int i, j, temp;

    if (!arr || size <= 1)
        return;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Step 1: Normalize values to their index positions
void	map_to_indexes(t_stack *a)
{
	int		*sorted;
	int		i;
	t_list	*current;

	// Create a sorted copy of the stack
	sorted = malloc(a->size * sizeof(int));
	current = a->top;
	for (i = 0; i < a->size; i++)
	{
		sorted[i] = *(int *)current->content;
		current = current->next;
	}
	bubble_sort(sorted, a->size); // Assume a bubble_sort function exists

	// Map original values to their indexes
	current = a->top;
	while (current)
	{
		for (i = 0; i < a->size; i++)
		{
			if (*(int *)current->content == sorted[i])
			{
				*(int *)current->content = i;
				break;
			}
		}
		current = current->next;
	}

	free(sorted);
}

// Step 2: Perform Radix Sort
void	sort_medium_large(t_stack *a, t_stack *b)
{
	int	max_value;
	int	bit_count;
	int	i, j;

	// Step 1: Map values to indexes
	map_to_indexes(a);

	// Step 2: Find the largest value and calculate the number of bits
	max_value = find_max(a); // Now it's the largest index
	bit_count = count_bits(max_value);

	// Step 3: Radix Sort
	i = 0;
	while (i < bit_count)
	{
		j = 0;
		int size = a->size; // Fixed size for inner loop
		while (j < size)
		{
			if (((*(int *)a->top->content >> i) & 1) == 0)
				pb(a, b); // Push to B if the current bit is 0
			else
				ra(a); // Rotate if the current bit is 1
			j++;
		}

		// Push all elements back from B to A
		while (b->size > 0)
			pa(a, b);

		i++;
	}
}
