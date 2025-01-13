/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_placement_logic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:41:10 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/12 22:09:00 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*   is_direct_placement                                                      */
/*                                                                            */
/*   Checks if a number can be directly placed at the top of the stack.       */
/*                                                                            */
/*   @param stack: Pointer to the stack.                                      */
/*   @param number: The number to evaluate.                                   */
/*   @param is_stack_a: Flag for stack A (1) or stack B (0).                  */
/*   @return: 1 if direct placement is possible, 0 otherwise.                 */
/*                                                                            */
/* ************************************************************************** */

static int	is_direct_placement(t_stack *stack, int number, int is_stack_a)
{
	if (is_stack_a)
		return (number < stack->nbr && number > get_last_node(stack)->nbr);
	return (number > stack->nbr && number < get_last_node(stack)->nbr);
}

/* ************************************************************************** */
/*                                                                            */
/*   is_extreme_placement                                                     */
/*                                                                            */
/*   Checks if a number should be placed at an extreme position in the stack. */
/*                                                                            */
/*   @param stack: Pointer to the stack.                                      */
/*   @param number: The number to evaluate.                                   */
/*   @param is_stack_a: Flag for stack A (1) or stack B (0).                  */
/*   @return: The index for extreme placement or -1 if not applicable.        */
/*                                                                            */
/* ************************************************************************** */

static int	is_extreme_placement(t_stack *stack, int number, int is_stack_a)
{
	if (is_stack_a && (number > find_max_value(stack) || number < find_min_value(stack)))
		return (find_index_in_stack(stack, find_min_value(stack)));
	if (!is_stack_a && (number > find_max_value(stack) || number < find_min_value(stack)))
		return (find_index_in_stack(stack, find_max_value(stack)));
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*   calculate_position                                                       */
/*                                                                            */
/*   Calculates the position for a number in the stack.                       */
/*                                                                            */
/*   @param stack: Pointer to the stack.                                      */
/*   @param number: The number to evaluate.                                   */
/*   @param is_stack_a: Flag for stack A (1) or stack B (0).                  */
/*   @return: The calculated position for the number in the stack.            */
/*                                                                            */
/* ************************************************************************** */

static int	calculate_position(t_stack *stack, int number, int is_stack_a)
{
	int		position;
	t_stack	*next_node;

	position = 1;
	next_node = stack->next;
	while (stack &&
		   ((is_stack_a && (stack->nbr > number || (next_node && next_node->nbr < number))) ||
			(!is_stack_a && (stack->nbr < number || (next_node && next_node->nbr > number)))))
	{
		stack = stack->next;
		next_node = stack ? stack->next : NULL;
		position++;
	}
	return (position);
}

/* ************************************************************************** */
/*                                                                            */
/*   determine_position_in_stack_a                                            */
/*                                                                            */
/*   Determines where a number should be placed in stack A.                   */
/*                                                                            */
/*   @param stack_a: Pointer to stack A.                                      */
/*   @param number: The number to evaluate.                                   */
/*   @return: The position for the number in stack A.                         */
/*                                                                            */
/* ************************************************************************** */

int	determine_position_in_stack_a(t_stack *stack_a, int number)
{
	int	position;

	if (is_direct_placement(stack_a, number, 1))
		return (0);
	position = is_extreme_placement(stack_a, number, 1);
	if (position != -1)
		return (position);
	return (calculate_position(stack_a, number, 1));
}

/* ************************************************************************** */
/*                                                                            */
/*   determine_position_in_stack_b                                            */
/*                                                                            */
/*   Determines where a number should be placed in stack B.                   */
/*                                                                            */
/*   @param stack_b: Pointer to stack B.                                      */
/*   @param number: The number to evaluate.                                   */
/*   @return: The position for the number in stack B.                         */
/*                                                                            */
/* ************************************************************************** */

int	determine_position_in_stack_b(t_stack *stack_b, int number)
{
	int	position;

	if (is_direct_placement(stack_b, number, 0))
		return (0);
	position = is_extreme_placement(stack_b, number, 0);
	if (position != -1)
		return (position);
	return (calculate_position(stack_b, number, 0));
}