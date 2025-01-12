/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+    */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:36 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/12 00:36:00 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

#include "../../include/push_swap.h"

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
static void	add_to_stack(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = stack_new(value);
	if (!*stack)
		*stack = new_node;
	else
	{
		last_node = *stack;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
		new_node->prev = last_node;
	}
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
	t_stack	*stack_a;
	char	**split_arguments;
	int		index;
	int		parsed_value;

	stack_a = NULL;
	split_arguments = ft_split(argv[1], ' ');
	if (!split_arguments || !*split_arguments)
	{
		if (split_arguments)
			free_2d_array(split_arguments);
		fatal_error();
	}
	index = 0;
	while (split_arguments[index])
	{
		parsed_value = parse_strict_atoi(split_arguments[index]);
		stack_add_back(&stack_a, stack_new(parsed_value));
		index++;
	}
	free_2d_array(split_arguments);
	return (stack_a);
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
/*   @param argc: The argument count.                                         */
/*   @param argv: The argument vector.                                        */
/*   @param stack: A pointer to the pointer of the stack to populate.         */
/*                                                                            */
/* ************************************************************************** */
void	validate_arguments(int argc, char **argv, t_stack **stack)
{
	int	index;
	int	parsed_value;

	*stack = NULL;
	if (argc == 2)
		*stack = validate_two_args(argv);
	else
	{
		index = 1;
		while (index < argc)
		{
			parsed_value = parse_strict_atoi(argv[index]);
			add_to_stack(stack, parsed_value);
			index++;
		}
	}
	if (has_duplicates(*stack))
		handle_error(*stack, NULL);
}