/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:15 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/04 21:44:22 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// Parse arguments and initialize the stack
void parse_arguments(int argc, char **argv, t_stack **stack)
{
	int i;
	long value;
	t_stack *new_node;
	t_stack *tail;

	i = 1;
    if (argc == 2)
    	*stack = two_args(argv);
	else
		while (i < argc)
		{
			value = parse_strict_atoi(argv[i]); // Convert argument to long
			if (value < MIN_INT || value > MAX_INT)
				fatal_error();
			new_node = stack_new(value); // Create a new stack node
			if (*stack == NULL)
				*stack = new_node;
			else
			{
				tail = *stack;
				while (tail->next)
					tail = tail->next;
				tail->next = new_node;
				new_node->prev = tail;
			}
			i++;
		}
}
