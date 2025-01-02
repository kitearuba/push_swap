/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:23:10 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/27 22:32:52 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int cost_rotate_ab(t_stack *a, t_stack *b, int c)
{
    int cost;
    ft_printf("Check 6");
    cost = find_insert_pos(b, c);
    ft_printf("Check 7");
    if (cost < find_stack_index(a, c))
        cost = find_stack_index(a, c);
    ft_printf("Check 8");
    return cost;
}

int cost_reverse_rotate_ab(t_stack *a, t_stack *b, int c)
{
    int cost;

    cost = 0;
    if (find_insert_pos(b, c))
        cost = list_size(b) - find_insert_pos(b, c);
    if ((cost < (list_size(a) - find_stack_index(a, c))) && find_stack_index(a, c))
        cost = list_size(a) - find_stack_index(a, c);
    return cost;
}

int cost_rotate_a_reverse_b(t_stack *a, t_stack *b, int c)
{
    int cost;

    cost = 0;
    if (find_insert_pos(b, c))
        cost = list_size(b) - find_insert_pos(b, c);
    cost += find_stack_index(a, c);
    return cost;
}

int cost_reverse_a_rotate_b(t_stack *a, t_stack *b, int c)
{
    int cost;

    cost = 0;
    if (find_stack_index(a, c))
        cost = list_size(a) - find_stack_index(a, c);
    cost += find_insert_pos(b, c);
    return cost;
}
