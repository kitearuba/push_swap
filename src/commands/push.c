/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:57:02 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/23 16:57:08 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_stack *a, t_stack *b)
{
    if (b->size == 0)
        return;
    int value = pop(b); // Remove the top element from stack `b`
    push(a, value);     // Add it to stack `a`
}

void pb(t_stack *a, t_stack *b)
{
    pa(b, a); // Reverse the logic of `pa`
}
