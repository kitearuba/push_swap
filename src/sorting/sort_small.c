/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:37 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/22 11:59:26 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_small(t_stack *a)
{
    t_node *first = a->top;
    t_node *second = first->next;
    t_node *third = second ? second->next : NULL;

    if (first->value > second->value)
        sa(a); // Swap first two elements
    if (third && first->value > third->value)
        rra(a); // Rotate the last element to the top
    if (second->value > third->value)
        sa(a); // Swap first two elements again
}
