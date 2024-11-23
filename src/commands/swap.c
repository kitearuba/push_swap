/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:57:55 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/23 16:58:05 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack *a)
{
    if (a->size < 2)
        return;
    int temp = a->top->value;
    a->top->value = a->top->next->value;
    a->top->next->value = temp;
}

void sb(t_stack *b)
{
    sa(b); // Same logic as `sa` but applied to stack `b`
}

void ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}
