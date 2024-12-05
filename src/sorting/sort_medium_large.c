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

// Count the number of bits needed to represent the maximum value
int count_bits(int max)
{
    int bits = 0;
    while (max > 0)
    {
        max /= 2;
        bits++;
    }
    return (bits);
}

// Quick Sort Implementation for Array
void quick_sort(int *arr, int left, int right)
{
    if (left >= right)
        return;

    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    quick_sort(arr, left, j);
    quick_sort(arr, i, right);
}

// Step 1: Normalize values to their index positions
void map_to_indexes(t_stack *a)
{
    int *sorted;
    int i;
    t_list *current;

    // Allocate memory for the sorted array
    sorted = malloc(a->size * sizeof(int));
    if (!sorted)
        return; // Handle allocation failure

    // Copy stack values into the array
    current = a->top;
    for (i = 0; i < a->size; i++)
    {
        sorted[i] = *(int *)current->content;
        current = current->next;
    }

    // Sort the array
    quick_sort(sorted, 0, a->size - 1);

    // Map original stack values to their sorted indices
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
void sort_medium_large(t_stack *a, t_stack *b)
{
    int max_value;
    int bit_count;
    int i, j;

    // Step 1: Map values to indexes
    map_to_indexes(a);

    // Step 2: Find the largest value and calculate the number of bits
    max_value = find_max(a); // Now it's the largest index
    bit_count = count_bits(max_value);

    // Step 3: Radix Sort
    for (i = 0; i < bit_count; i++)
    {
        int size = a->size;

        for (j = 0; j < size; j++)
        {
            int top_value = *(int *)a->top->content;

            if (((top_value >> i) & 1) == 0)
                pb(a, b); // Push to B if the current bit is 0
            else
                ra(a); // Rotate if the current bit is 1
        }

        // Push all elements back from B to A
        while (b->size > 0)
        {
            pa(a, b);
        }
    }
}
