/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:15 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/12 01:04:10 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*   is_sorted                                                                */
/*                                                                            */
/*   Checks if the stack is sorted in ascending order.                        */
/*                                                                            */
/*   @param stack: Pointer to the stack to check.                             */
/*   @return: 1 if the stack is sorted, 0 otherwise.                          */
/*                                                                            */
/* ************************************************************************** */

int	is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return (0);
        stack = stack->next;
    }
    return (1);
}