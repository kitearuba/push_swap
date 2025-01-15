/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_placement_logic.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:41:10 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/15 20:36:07 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	determine_position_in_b(t_stack *stack_b, int number_to_place)
{
	int		position;
	t_stack	*next_node;

	position = 1;
	if (number_to_place > stack_b->nbr
		&& number_to_place < get_last_node(stack_b)->nbr)
		position = 0;
	else if (number_to_place > find_max_value(stack_b)
		|| number_to_place < find_min_value(stack_b))
		position = find_index_in_stack(stack_b, find_max_value(stack_b));
	else
	{
		next_node = stack_b->next;
		while (stack_b->nbr < number_to_place
			|| next_node->nbr > number_to_place)
		{
			stack_b = stack_b->next;
			next_node = stack_b->next;
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

int	determine_position_in_a(t_stack *stack_a, int number_to_place)
{
	int		position;
	t_stack	*next_node;

	position = 1;
	if (number_to_place < stack_a->nbr && number_to_place > get_last_node
		(stack_a)->nbr)
		position = 0;
	else if (number_to_place > find_max_value(stack_a)
		|| number_to_place < find_min_value(stack_a))
		position = find_index_in_stack(stack_a, find_min_value(stack_a));
	else
	{
		next_node = stack_a->next;
		while (stack_a->nbr > number_to_place
			||next_node->nbr < number_to_place)
		{
			stack_a = stack_a->next;
			next_node = stack_a->next;
			position++;
		}
	}
	return (position);
}
