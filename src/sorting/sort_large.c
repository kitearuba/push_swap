/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:17 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/24 21:48:54 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_large(t_stack *a, t_stack *b)
{
    int		max_bits;
    int		max_value;
    int		i;
    int		j;
    t_node	*current;

    max_bits = 0;
    max_value = a->size - 1;
    i = 0;
    j = 0;
    // Determine the number of bits needed for the largest value
    while ((max_value >> max_bits) != 0)
        max_bits++;

    while (i < max_bits)
    {
        current = a->top;
        while (j < a->size)
        {
            if (((current->value >> i) & 1) == 0)
                pb(a, b); // Push to stack B if the bit is 0
            else
                ra(a); // Rotate stack A if the bit is 1
            current = a->top;
            j++;
        }
        while (b->top)
            pa(a, b); // Push everything back to stack A
        i++;
    }
}

