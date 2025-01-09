/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:37 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/04 22:24:44 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

/**
 * move_to_top - Moves the element at the given index to the top of the stack.
 * @stack: Pointer to stack A.
 * @index: Index of the element to move to the top.
 * Description:
 * - Rotates the stack up or down to bring the element to the top efficiently.
 */
static void move_to_top(t_stack **stack, int index)
{
    int size;
    int rotations;

    size = stack_size(*stack); // Replace with your function to calculate size.
    if (size == 0 || index < 0 || index >= size)
        return;

    if (index <= size / 2)
    {
        rotations = index;
        while (rotations-- > 0)
            ra(stack, 0); // Rotate up.
    }
    else
    {
        rotations = size - index;
        while (rotations-- > 0)
            rra(stack, 0); // Rotate down.
    }
}

/**
 * push_smallest_to_b - Moves the smallest element from stack A to stack B.
 * @a: Pointer to stack A.
 * @b: Pointer to stack B.
 * Description:
 * - Finds the index of the smallest element in stack A.
 * - Moves the smallest element to the top of stack A.
 * - Pushes it to stack B.
 */
static void push_smallest_to_b(t_stack **a, t_stack **b)
{
    int min_index;

    min_index = find_index(*a, ft_min(*a));
    move_to_top(a, min_index);
    pb(a, b, 0);                    // Push the smallest element to stack B.
}

/**
 * sort_small - Sorts stacks of up to five elements.
 * @a: Pointer to stack A.
 * @b: Pointer to stack B (used as auxiliary stack).
 * Description:
 * - For three elements, calls sort_three.
 * - For more than three elements, moves the smallest element(s) to stack B,
 *   then sorts the remaining elements using sort_three and pushes back.
 */
void sort_small(t_stack **a)
{
    t_stack *b;

    b = NULL;
    if (stack_size(*a) == 2)
    {
        if ((*a)->nbr > (*a)->next->nbr)
            sa(a, 0); // Swap if the first element is greater than the second
        return ;
    }
    if (stack_size(*a) <= 3) // Replace with your function to get stack size.
    {
        sort_three(a); // Sort three elements directly.
        return ;
    }

    while (stack_size(*a) > 3)
        push_smallest_to_b(a, &b); // Push smallest elements to B.

    sort_three(a); // Sort remaining three elements in A.

    while (b) // Push all elements back from B to A.
       pa(a, &b, 0);
}
