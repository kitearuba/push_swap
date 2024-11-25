/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:17 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/22 12:06:10 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_large(t_stack *a, t_stack *b)
{
    int		max_bits;
    int		max_value;
    int		i;
    int		j;

    max_bits = 0;
    max_value = a->size - 1;
    i = 0;
    j = 0;
    // Determine the number of bits needed for the largest value
    while ((max_value >> max_bits) != 0)
        max_bits++;

    while (i < max_bits)
    {
        while (j < a->size)
        {
            if ((*(int *)a->top->content >> i) & 1)
                ra(a); // Rotate stack A if the bit is 1
            else
                pb(a, b); // Push to stack B if the bit is 0
            j++;
        }
        while (b->top)
            pa(a, b); // Push everything back to stack A
        i++;
    }
}
