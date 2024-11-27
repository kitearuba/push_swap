/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:28 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/27 18:37:58 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Main sorting function for medium-sized inputs
void sort_medium(t_stack *a, t_stack *b)
{
    while (a->size > 0)
        push_min_to_b(a, b); // Push smallest element to B
    while (b->size > 0)
        pa(a, b); // Push all back to A
}
