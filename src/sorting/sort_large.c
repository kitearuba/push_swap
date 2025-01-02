/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:17 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/25 18:12:35 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void sort_large(t_stack *a, t_stack *b)
{
    ft_printf("Check 1");
    while (list_size(a) > 3)
        apply_min_cost_move(&a, &b);
    ft_printf("Check 2");
    sort_three(a);
    while (list_size(b) > 0)
        apply_min_cost_move(&b, &a);
}
