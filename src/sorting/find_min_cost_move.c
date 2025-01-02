/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_cost_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:23:10 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/27 22:32:52 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int find_min_cost_move(t_stack *a, t_stack *b)
{
    ft_printf("Check 4");
    int min_cost = MAX_INT;
    int current_cost;
    int target_number = 0;
    t_list *temp = a->top;

    while (temp)
    {
        ft_printf("Check 5");
        current_cost = cost_rotate_ab(a, b, *(int *)temp->content);
        ft_printf("Check 6");
        if (current_cost < min_cost)
        {
            ft_printf("Check ?");
            min_cost = current_cost;
            target_number = *(int *)temp->content;
        }
        // Repeat for other cost cases...
        temp = temp->next;
    }
    return target_number;
}

/*
int find_min_cost_move(t_stack *a, t_stack *b)
{
    int min_cost = INT_MAX;
    int current_cost;
    int target_number = 0;
    t_stack *temp = a;

    while (temp)
    {
        current_cost = cost_rotate_ab(a, b, temp->nbr);
        if (current_cost < min_cost)
        {
            min_cost = current_cost;
            target_number = temp->nbr;
        }
        current_cost = cost_reverse_rotate_ab(a, b, temp->nbr);
        if (current_cost < min_cost)
        {
            min_cost = current_cost;
            target_number = temp->nbr;
        }
        current_cost = cost_rotate_a_reverse_b(a, b, temp->nbr);
        if (current_cost < min_cost)
        {
            min_cost = current_cost;
            target_number = temp->nbr;
        }
        current_cost = cost_reverse_a_rotate_b(a, b, temp->nbr);
        if (current_cost < min_cost)
        {
            min_cost = current_cost;
            target_number = temp->nbr;
        }
        temp = temp->next;
    }
    return target_number;
}
*/