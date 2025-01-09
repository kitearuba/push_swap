/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:15 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/25 18:41:59 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// is_sorted.c
// Checks if the stack is sorted.
int    is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return (0);
        stack = stack->next;
    }
    return (1);
}
