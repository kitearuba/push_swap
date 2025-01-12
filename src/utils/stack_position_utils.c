/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_position_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:41:10 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/05 21:30:17 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*   find_index_in_stack                                                      */
/*                                                                            */
/*   Finds the index of a specific number in a stack.                         */
/*                                                                            */
/*   @param stack: The stack to search.                                       */
/*   @param target_value: The number to find.                                 */
/*   @return: The index of the number in the stack.                           */
/*                                                                            */
/* ************************************************************************** */

int	find_index_in_stack(t_stack *stack, int target_value)
{
	int	index;

	index = 0;
	while (stack && stack->nbr != target_value)
	{
		index++;
		stack = stack->next;
	}
	return (index);
}

/* ************************************************************************** */
/*                                                                            */
/*   determine_position_in_stack_b                                            */
/*                                                                            */
/*   Determines where a number should be placed in stack B.                   */
/*                                                                            */
/*   @param stack_b: Pointer to stack B.                                      */
/*   @param number_to_place: The number to evaluate.                          */
/*   @return: The position for the number in stack B.                         */
/*                                                                            */
/* ************************************************************************** */

int	determine_position_in_stack_b(t_stack *stack_b, int number_to_place)
{
	int		position;
	t_stack	*next_node;

	position = 1;
	if (number_to_place > stack_b->nbr &&
		number_to_place < stack_last(stack_b)->nbr)
		position = 0;
	else if (number_to_place > find_max_value(stack_b) ||
			 number_to_place < find_min_value(stack_b))
		position = find_index_in_stack(stack_b, find_max_value(stack_b));
	else
	{
		next_node = stack_b->next;
		while (stack_b &&
			   (stack_b->nbr < number_to_place || next_node->nbr > number_to_place))
		{
			stack_b = stack_b->next;
			next_node = stack_b ? stack_b->next : NULL;
			position++;
		}
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
/*   @param number_to_place: The number to evaluate.                          */
/*   @return: The position for the number in stack A.                         */
/*                                                                            */
/* ************************************************************************** */

int	determine_position_in_stack_a(t_stack *stack_a, int number_to_place)
{
	int		position;
	t_stack	*next_node;

	position = 1;
	if (number_to_place < stack_a->nbr &&
		number_to_place > stack_last(stack_a)->nbr)
		position = 0;
	else if (number_to_place > find_max_value(stack_a) ||
			 number_to_place < find_min_value(stack_a))
		position = find_index_in_stack(stack_a, find_min_value(stack_a));
	else
	{
		next_node = stack_a->next;
		while (stack_a &&
			   (stack_a->nbr > number_to_place || next_node->nbr < number_to_place))
		{
			stack_a = stack_a->next;
			next_node = stack_a ? stack_a->next : NULL;
			position++;
		}
	}
	return (position);
}