/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:32:55 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/08 21:30:17 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * handle_error - Handles errors by cleaning up and exiting the program.
 * @error_message: The error message to display.
 * @a: Pointer to stack A.
 * @b: Pointer to stack B.
 *
 * Description:
 * - Frees both stacks (if they exist) using stack_free.
 * - Prints an error message to STDERR if provided.
 * - Exits the program with EXIT_FAILURE.
 */
void handle_error(t_stack *a, t_stack *b)
{
	if (a)
		stack_free(&a); // Pass the address of the pointer.
	if (b)
		stack_free(&b); // Pass the address of the pointer.
	fatal_error();
}
