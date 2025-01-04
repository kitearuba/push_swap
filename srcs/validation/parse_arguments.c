/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:15 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/25 18:41:59 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Parses and validates input arguments, then constructs the stack.
 * Replaces: ft_stack_new, ft_add_back
 */
void parse_arguments(int argc, char **argv, t_stack **stack)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (!is_number(argv[i]))
            handle_error("Invalid number", *stack, NULL);
        append_stack_node(stack, create_stack_node(ft_atoi(argv[i])));
        i++;
    }
    if (has_duplicates(*stack))
        handle_error("Duplicate found", *stack, NULL);
}
