/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:28 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/25 18:07:43 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	partition_stack(t_stack *a, t_stack *b, int pivot)
{
    int i = a->size;
    while (i > 0)
    {
        if (*(int *)a->top->content < pivot)
            pb(a, b); // Push to stack B if less than pivot
        else
            ra(a); // Rotate stack A
        i--;
    }
}

void	sort_medium(t_stack *a, t_stack *b)
{
    int median;

    if (a->size <= 3)
    {
        sort_small(a, b);
        return;
    }
    median = calculate_median(a);
    partition_stack(a, b, median);
    sort_small(a, b);
    while (b->top)
        pa(a, b); // Push elements back to stack A
}
