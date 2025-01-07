/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:17 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/04 22:37:42 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                          Sorting Large Stacks                             */
/* ************************************************************************** */

/**
 * rotate_and_push - Helper to optimize rotation and push operation.
 * @a: Pointer to stack A.
 * @b: Pointer to stack B.
 * Description:
 * - Uses `rotate_type_ab` to determine the optimal rotation type.
 * - Moves the element to stack B using the determined rotation.
 */
void rotate_and_push(t_stack *a, t_stack *b)
{
    int rotation_type;

    rotation_type = rotate_type_ab(a, b);
    if (rotation_type == ROTATE_RA)
        ra(a);
    else if (rotation_type == ROTATE_RRA)
        rra(a);
    pb(a, b);
}

/**
 * sort_big - Main sorting logic for large stacks.
 * @a: Pointer to stack A.
 * @b: Pointer to stack B.
 * Description:
 * - Moves elements from stack A to stack B using optimal rotations.
 * - Returns elements to stack A in sorted order.
 */
void sort_big(t_stack *a, t_stack *b)
{
    while (a->size > 3)
        rotate_and_push(a, b);
    sort_three(a);; // Sort the remaining three elements
    while (b->size > 0)
    {
        ft_case_rrarrb(a, b);
        pa(a, b);
    }
}
