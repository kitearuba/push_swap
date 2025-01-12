/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:59:37 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/12 01:41:00 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*   sort_three                                                               */
/*                                                                            */
/*   Sorts a stack of exactly three elements using stack operations.          */
/*                                                                            */
/* ************************************************************************** */
void	sort_three(t_stack **stack)
{
    int	top;
    int	middle;
    int	bottom;

    top = (*stack)->nbr;
    middle = (*stack)->next->nbr;
    bottom = (*stack)->next->next->nbr;
    if (top > middle && middle < bottom && top < bottom)
        sa(stack, 0);
    else if (top > middle && middle > bottom && top > bottom)
    {
        sa(stack, 0);
        rra(stack, 0);
    }
    else if (top > middle && middle < bottom && top > bottom)
        ra(stack, 0);
    else if (top < middle && middle > bottom && top < bottom)
    {
        sa(stack, 0);
        ra(stack, 0);
    }
    else if (top < middle && middle > bottom && top > bottom)
        rra(stack, 0);
}