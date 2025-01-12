/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:52:36 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/12 00:32:00 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*   get_last_node                                                            */
/*                                                                            */
/*   Retrieves the last node of the stack.                                    */
/*                                                                            */
/*   @param stack: Pointer to the stack.                                      */
/*   @return: Pointer to the last node, or NULL if the stack is empty.        */
/*                                                                            */
/* ************************************************************************** */

t_stack	*get_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/* ************************************************************************** */
/*                                                                            */
/*   get_stack_size                                                           */
/*                                                                            */
/*   Calculates the size of the stack.                                        */
/*                                                                            */
/*   @param stack: Pointer to the stack.                                      */
/*   @return: The number of elements in the stack.                            */
/*                                                                            */
/* ************************************************************************** */

int	get_stack_size(t_stack *stack)
{
	size_t	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*   find_min_value                                                           */
/*                                                                            */
/*   Finds and returns the smallest value in the stack.                       */
/*                                                                            */
/*   @param stack: Pointer to the stack.                                      */
/*   @return: The smallest value in the stack.                                */
/*                                                                            */
/* ************************************************************************** */

int	find_min_value(t_stack *stack)
{
	int	min_value;

	if (!stack)
		fatal_error(); // Handle empty stack gracefully
	min_value = stack->nbr;
	while (stack)
	{
		if (stack->nbr < min_value)
			min_value = stack->nbr;
		stack = stack->next;
	}
	return (min_value);
}

/* ************************************************************************** */
/*                                                                            */
/*   find_max_value                                                           */
/*                                                                            */
/*   Finds and returns the largest value in the stack.                        */
/*                                                                            */
/*   @param stack: Pointer to the stack.                                      */
/*   @return: The largest value in the stack.                                 */
/*                                                                            */
/* ************************************************************************** */

int	find_max_value(t_stack *stack)
{
	int	max_value;

	if (!stack)
		fatal_error(); // Handle empty stack gracefully
	max_value = stack->nbr;
	while (stack)
	{
		if (stack->nbr > max_value)
			max_value = stack->nbr;
		stack = stack->next;
	}
	return (max_value);
}