/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+    */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:36 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/15 20:54:10 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*   stack_new                                                                */
/*                                                                            */
/*   Creates a new stack node with the given value.                           */
/*                                                                            */
/* ************************************************************************** */
static t_stack	*stack_new(long value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
	{
		stack_free(&new_node);
		fatal_error();
	}
	new_node->nbr = value;
	new_node->next = NULL;
	return (new_node);
}

/* ************************************************************************** */
/*                                                                            */
/*   add_to_stack                                                             */
/*                                                                            */
/*   Adds a new node with the given value to the stack.                       */
/*   Creates a new node using `stack_new` and appends it to the end of the    */
/*   stack. If the stack is empty, the new node becomes the first node.       */
/*                                                                            */
/*   @param stack: A pointer to the pointer of the stack.                     */
/*   @param value: The value to add to the stack.                             */
/*                                                                            */
/* ************************************************************************** */
static void	add_to_stack(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(get_last_node(*stack))->next = stack_new;
}

/* ************************************************************************** */
/*                                                                            */
/*   has_duplicates                                                           */
/*                                                                            */
/*   Checks for duplicate values in the stack.                                */
/*   Iterates through each node in the stack and compares its value           */
/*   with the values of subsequent nodes. If a duplicate is found,            */
/*   it immediately triggers an error using `handle_error`.                   */
/*                                                                            */
/*   @param stack: The stack to check for duplicates.                         */
/*   @return: Always returns 0 if no duplicates are found.                    */
/*                                                                            */
/* ************************************************************************** */
static int	has_duplicates(t_stack *stack)
{
	t_stack	*current_node;
	t_stack	*comparison_node;

	current_node = stack;
	while (current_node)
	{
		comparison_node = current_node->next;
		while (comparison_node)
		{
			if (current_node->nbr == comparison_node->nbr)
				handle_error(stack, NULL);
			comparison_node = comparison_node->next;
		}
		current_node = current_node->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*   validate_two_args                                                        */
/*                                                                            */
/*   Validates and parses arguments when only one argument is provided.       */
/*   Splits the single argument string into individual numbers using          */
/*   `ft_split`, parses each number with `parse_strict_atoi`, and adds        */
/*   them to the stack.                                                       */
/*                                                                            */
/*   @param argv: The array of command-line arguments.                        */
/*   @return: The constructed stack with the parsed values.                   */
/*                                                                            */
/* ************************************************************************** */
static t_stack	*validate_two_args(char **argv)
{
	t_stack	*a;
	char	**split_args;
	int		index;
	int		parsed_value;

	a = NULL;
	split_args = ft_split(argv[1], ' ');
	if (!split_args || !*split_args)
	{
		if (split_args)
			free_2d_array(split_args);
		fatal_error();
	}
	index = 0;
	while (split_args[index])
	{
		parsed_value = parse_strict_atoi(split_args[index], &a, split_args);
		add_to_stack(&a, stack_new(parsed_value));
		index++;
	}
	free_2d_array(split_args);
	return (a);
}

/* ************************************************************************** */
/*                                                                            */
/*   validate_arguments                                                       */
/*                                                                            */
/*   Main validation function for command-line arguments.                     */
/*   Validates the input arguments and constructs the stack. If only one      */
/*   argument is provided, it calls `validate_two_args`. Otherwise, it        */
/*   iterates through the arguments, parses them, and adds each value         */
/*   to the stack using `add_to_stack`.                                       */
/*                                                                            */
/*   @param stack: A pointer to the pointer of the stack to populate.         */
/*                                                                            */
/* ************************************************************************** */
t_stack	*validate_arguments(int argc, char **argv)
{
	t_stack	*stack;
	int		index;
	int		parsed_value;

	stack = NULL;
	index = 1;
	if (argc == 2)
		stack = validate_two_args(argv);
	else
	{
		while (index < argc)
		{
			parsed_value = parse_strict_atoi(argv[index], &stack, NULL);
			add_to_stack(&stack, stack_new(parsed_value));
			index++;
		}
	}
	if (has_duplicates(stack))
		handle_error(stack, NULL);
	return (stack);
}
