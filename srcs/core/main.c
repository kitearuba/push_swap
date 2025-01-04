/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:36 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/25 18:33:21 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// main.c
// Entry point for the push_swap program.
int main(int argc, char **argv)
{
    t_stack *stack_a = NULL;

    if (argc < 2)
        return (0);

    parse_arguments(argc, argv, &stack_a);
    if (!is_sorted(stack_a))
        sort_stack(&stack_a);

    free_stack(&stack_a);
    return (0);
}
