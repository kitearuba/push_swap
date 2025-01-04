/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_sort_big.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:58:33 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/04 22:58:43 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
 * is_min_or_max - Checks if the top element in stack A is the minimum or maximum.
 * @a: Pointer to stack A.
 * Return: 1 if the element is a minimum or maximum, 0 otherwise.
 */
int is_min_or_max(t_stack *a)
{
    t_list *current;
    int min;
    int max;

    if (!a || !a->top)
        return (0);
    current = a->top;
    min = current->nbr;
    max = current->nbr;
    while (current)
    {
        if (current->nbr < min)
            min = current->nbr;
        if (current->nbr > max)
            max = current->nbr;
        current = current->next;
    }
    return ((a->top->nbr == min) || (a->top->nbr == max));
}

/**
 * find_min_index - Finds the index of the minimum element in stack A.
 * @a: Pointer to stack A.
 * Return: Index of the minimum element.
 */
int find_min_index(t_stack *a)
{
    t_list *current;
    int min;
    int min_index;
    int index;

    if (!a || !a->top)
        handle_error("Stack is empty", a, NULL);
    current = a->top;
    min = current->nbr;
    min_index = 0;
    index = 0;
    while (current)
    {
        if (current->nbr < min)
        {
            min = current->nbr;
            min_index = index;
        }
        current = current->next;
        index++;
    }
    return (min_index);
}

/**
 * find_optimal_rotation - Determines the optimal index for rotation.
 * @a: Pointer to stack A.
 * @b: Pointer to stack B.
 * Return: Index of the optimal element to rotate.
 */
int find_optimal_rotation(t_stack *a, t_stack *b)
{
    t_list *current;
    int index;
    int optimal_index;
    int min_cost;
    int current_cost;

    if (!a || !a->top)
        handle_error("Stack A is empty", a, b);
    current = a->top;
    index = 0;
    optimal_index = 0;
    min_cost = INT_MAX;
    while (current)
    {
        current_cost = calculate_rotation_cost(index, a->size, b);
        if (current_cost < min_cost)
        {
            min_cost = current_cost;
            optimal_index = index;
        }
        current = current->next;
        index++;
    }
    return (optimal_index);
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


