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
int	main(int argc, char **argv)
{
    t_stack	*a;

    if (argc < 2)
        return (0);
    a =  validate_arguments(argc, argv);
    if (is_sorted(a))
    {
        stack_free(&a);
        return (0);
    }
    sort_stack(&a);
    stack_free(&a);
    return (0);
}