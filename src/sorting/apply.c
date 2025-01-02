/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:24:26 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/02 19:24:32 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void apply_rotate_ab(t_stack **a, t_stack **b, int value, char strategy)
{
    while (*(int *)(*a)->top->content != value && *(int *)(*b)->top->content != value)
    {
        if (strategy == 'b')
            rr(*a, *b);
    }
}

void    apply_reverse_rotate_ab(t_stack **a, t_stack **b, int value, char strategy)
{
    while (*(int *)(*a)->top->content != value && *(int *)(*b)->top->content  != value)
    {
        if (strategy == 'b')
            rrr(*a, *b);
    }
}

void    apply_rotate_a_reverse_b(t_stack **a, t_stack **b, int value)
{
    while (*(int *)(*a)->top->content != value || *(int *)(*b)->top->content != value)
    {
        if (*(int *)(*a)->top->content != value)
            ra(*a);
        if (*(int *)(*b)->top->content != value)
            rrb(*b);
    }
}

void    apply_reverse_a_rotate_b(t_stack **a, t_stack **b, int value)
{
    while (*(int *)(*a)->top->content != value || *(int *)(*b)->top->content != value)
    {
        if (*(int *)(*a)->top->content != value)
            rra(*a);
        if (*(int *)(*b)->top->content != value)
            rb(*b);
    }
}
