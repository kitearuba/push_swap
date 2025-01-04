/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:15 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/25 18:41:59 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// has_duplicates.c
// Checks if the stack contains duplicate numbers.
int    has_duplicates(t_stack *stack)
{
    t_stack *outer;
    t_stack *inner;

    outer = stack;
    while (outer)
    {
        inner = outer->next;
        while (inner)
        {
            if (outer->nbr == inner->nbr)
                return (1);
            inner = inner->next;
        }
        outer = outer->next;
    }
    return (0);
}
