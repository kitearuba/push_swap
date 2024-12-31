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

void turkish_sort(t_stack *a, t_stack *b)
{
    while (list_size(a) > 3)
        apply_min_cost_move(&a, &b);
    sort_three(a);
    while (list_size(b) > 0)
        apply_min_cost_move(&b, &a);
}
