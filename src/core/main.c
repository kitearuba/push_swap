/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:36 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/12 00:32:00 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Main entry point for the push_swap program.
 * @param argc: The argument count.
 * @param argv: The argument vector containing the program name and inputs.
 *
 * Description:
 * - Initializes a stack `a` and validates the arguments.
 * - If the stack is already sorted, it exits early to avoid unnecessary processing.
 * - Calls the sorting function and frees allocated resources before exiting.
 *
 * Return Value:
 * - Returns 0 if the program exits successfully.
 */
int	main(int argument_count, char **argument_vector)
{
    t_stack	*stack_a;

    if (argument_count < 2)
        return (0);
    stack_a = NULL;
    validate_arguments(argument_count, argument_vector, &stack_a);
    if (is_sorted(stack_a))
    {
        stack_free(&stack_a);
        return (0);
    }
    sort_stack(stack_a);
    stack_free(&stack_a);
    return (0);
}