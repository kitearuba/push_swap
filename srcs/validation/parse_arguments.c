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

/**
 * Parses and validates input arguments, then constructs the stack.
 * Replaces: ft_stack_new, ft_add_back
 */
static void	process_tokens(char **tokens, t_stack **stack)
{
	int i;

	i = 0;
	while (tokens[i])
	{
		append_stack_node(stack, create_stack_node(parse_strict_atoi(tokens[i])));
		i++;
	}
    free_2d_array(tokens);
}

void	parse_arguments(int argc, char **argv, t_stack **stack)
{
	char	**tokens;
	int		i;

	if (argc == 2)
	{
		tokens = ft_split(argv[1], ' ');
		if (!tokens)
			handle_error("Memory allocation failed", NULL, NULL);
		process_tokens(tokens, stack);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			append_stack_node(stack, create_stack_node(parse_strict_atoi(argv[i])));
			i++;
		}
	}
	if (has_duplicates(*stack))
		handle_error("Duplicate found", *stack, NULL);
}
