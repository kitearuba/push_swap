/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push.c                                  :+:      :+:    :+:   */
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
    min_cost = MAX_INT;
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
