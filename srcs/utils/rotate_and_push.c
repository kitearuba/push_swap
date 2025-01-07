/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_sort_big_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:58:33 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/04 22:58:43 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                      Helper Functions for Turkish Sort                    */
/* ************************************************************************** */


/**
 * rotate_and_push - Rotates stack A to optimize element placement in stack B.
 * @a: Pointer to stack A.
 * @b: Pointer to stack B.
 */
void rotate_and_push(t_stack *a, t_stack *b)
{
	int target_index;

	target_index = find_optimal_rotation(a, b);
	move_to_top(a, target_index);
	pb(a, b);
}


/**
 * calculate_rotation_cost - Calculates the cost of rotating an element.
 * @index: Index of the element in stack A.
 * @size_a: Total size of stack A.
 * @b: Pointer to stack B.
 * Return: Total cost of rotations.
 */
int calculate_rotation_cost(int index, int size_a, t_stack *b)
{
	int cost_a;
	int cost_b;

	cost_a = (index <= size_a / 2) ? index : size_a - index;
	cost_b = calculate_b_rotation_cost(index, b);
	return (cost_a + cost_b);
}

/**
 * calculate_b_rotation_cost - Calculates rotation cost for placement in stack B.
 * @index: Index of the element in stack A (mapped to value).
 * @b: Pointer to stack B.
 * Return: Cost of placing the element in stack B.
 */
int calculate_b_rotation_cost(int index, t_stack *b)
{
	t_list *current;
	int cost;
	int position;

	if (!b || !b->top)
		return (0);
	current = b->top;
	position = find_target_position(index, b);
	if (position <= b->size / 2)
		cost = position;
	else
		cost = b->size - position;
	return (cost);
}

/**
 * find_target_position - Finds the best position for an element in stack B.
 * @index: Index of the element in stack A (mapped to value).
 * @b: Pointer to stack B.
 * Return: Position in stack B where the element should be placed.
 */
int find_target_position(int index, t_stack *b)
{
	t_list *current;
	int position;

	current = b->top;
	position = 0;
	while (current)
	{
		// Add logic for position determination
		current = current->next;
		position++;
	}
	return (position);
}
