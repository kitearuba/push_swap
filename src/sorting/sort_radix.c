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

int ft_rotate_type_ba(t_stack *a, t_stack *b) {
    int value = *(int *)b->top->content;

    if (value == ft_case_rarb_a(a, b, value))
        return ft_case_rarb_a(a, b, value);
    if (value == ft_case_rarrb_a(a, b, value))
        return ft_case_rarrb_a(a, b, value);
    if (value == ft_case_rrarrb_a(a, b, value))
        return ft_case_rrarrb_a(a, b, value);
    return ft_case_rrarb_a(a, b, value);
}

void sort_medium_large(t_stack *a, t_stack *b) {
    int chunk_size = a->size / 5; // Divide stack into 5 chunks
    int chunk_count = 5;         // Number of chunks
    int i;

    // Push elements to stack B, chunk by chunk
    for (i = 0; i < chunk_count; i++) {
        int lower_bound = i * chunk_size;
        int upper_bound = (i + 1) * chunk_size;

        while (has_values_in_range(a, lower_bound, upper_bound)) {
            int value = *(int *)a->top->content;

            if (value >= lower_bound && value < upper_bound) {
                pb(a, b); // Push to B
            } else {
                ra(a); // Rotate A to bring the correct element to the top
            }
        }
    }

    // Sort elements back into stack A
    while (b->size > 0) {
        int best_move = ft_rotate_type_ba(a, b); // Determine the best move
        int value = *(int *)b->top->content;

        // Apply rotation logic
        if (best_move == ft_case_rarb_a(a, b, value)) {
            ft_apply_rarb(&a, &b, value, 'b');
        } else if (best_move == ft_case_rarrb_a(a, b, value)) {
            ft_apply_rarrb(&a, &b, value, 'b');
        } else if (best_move == ft_case_rrarrb_a(a, b, value)) {
            ft_apply_rrarrb(&a, &b, value, 'b');
        } else if (best_move == ft_case_rrarb_a(a, b, value)) {
            ft_apply_rrarb(&a, &b, value, 'b');
        }
        pa(a, b); // Push back to stack A
    }

    // Final adjustment to bring the smallest number to the top of stack A
    int min_index = ft_find_index(a, ft_min(a));
    if (min_index <= a->size / 2) {
        while (*(int *)a->top->content != ft_min(a))
            ra(a);
    } else {
        while (*(int *)a->top->content != ft_min(a))
            rra(a);
    }
}
