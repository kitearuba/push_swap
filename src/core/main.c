/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:36 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/15 18:30:01 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*   main                                                                     */
/*                                                                            */
/*   Main entry point for the push_swap program.                              */
/*                                                                            */
/*   - Initializes a stack `a` and validates the arguments.                   */
/*   - If the stack is already sorted, exits early to avoid unnecessary       */
/*     processing.                                                            */
/*   - Calls sorting function and frees allocated resources before exiting.   */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc < 2)
		return (0);
	a = validate_arguments(argc, argv);
	if (is_sorted(a))
	{
		stack_free(&a);
		return (0);
	}
	sort_stack(&a);
	stack_free(&a);
	return (0);
}
