/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_min_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:23:10 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/27 22:32:52 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void apply_min_cost_move(t_stack **a, t_stack **b)
{
    ft_printf("Check 3");
    int cheapest = find_min_cost_move(*a, *b);
    ft_printf("%d\n", cheapest);
    if (cost_rotate_ab(*a, *b, cheapest) == find_min_cost_move(*a, *b))
        apply_rotate_ab(a, b, cheapest, 'b');
    else if (cost_reverse_rotate_ab(*a, *b, cheapest) == find_min_cost_move(*a, *b))
        apply_reverse_rotate_ab(a, b, cheapest, 'b');
    else if (cost_rotate_a_reverse_b(*a, *b, cheapest) == find_min_cost_move(*a, *b))
        apply_rotate_a_reverse_b(a, b, cheapest);
    else if (cost_reverse_a_rotate_b(*a, *b, cheapest) == find_min_cost_move(*a, *b))
        apply_reverse_a_rotate_b(a, b, cheapest);
}
