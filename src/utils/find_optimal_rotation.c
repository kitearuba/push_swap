/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optimal_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:41:10 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/12 03:57:00 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*   evaluate_rotation                                                        */
/*                                                                            */
/*   Evaluates rotation cases for a node and updates the best rotation.       */
/*                                                                            */
/*   @param a: Pointer to stack A.                                            */
/*   @param b: Pointer to stack B.                                            */
/*   @param node: Pointer to the current node being evaluated.                */
/*   @param best_rotation: Pointer to the best rotation value to update.      */
/*   @param cases: Array of rotation case functions for the operation.        */
/*                                                                            */
/* ************************************************************************** */
static void	evaluate_rotation(
	t_stack *a,
	t_stack *b,
	t_stack *node,
	int *best_rotation,
	int (*cases[4])(t_stack *, t_stack *, int))
{
	int	i;
	int	rotation_value;

	i = 0;
	while (i < 4)
	{
		rotation_value = cases[i](a, b, node->nbr);
		if (*best_rotation > rotation_value)
			*best_rotation = rotation_value;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*   find_optimal_rotation_ab                                                 */
/*                                                                            */
/*   Finds the best rotation type for moving an element from stack A to B.    */
/*                                                                            */
/*   @param a: Pointer to stack A.                                            */
/*   @param b: Pointer to stack B.                                            */
/*   @return: The most efficient rotation type as an integer.                 */
/*                                                                            */
/* ************************************************************************** */
int	find_optimal_rotation_ab(t_stack *a, t_stack *b)
{
	t_stack	*current;
	int		best_rotation;
	int		(*cases[4])(t_stack *, t_stack *, int);

	cases[0] = case_rarb;
	cases[1] = case_rrarrb;
	cases[2] = case_rarrb;
	cases[3] = case_rrarb;
	best_rotation = case_rrarrb(a, b, a->nbr);
	current = a;
	while (current)
	{
		evaluate_rotation(a, b, current, &best_rotation, cases);
		current = current->next;
	}
	return (best_rotation);
}

/* ************************************************************************** */
/*                                                                            */
/*   find_optimal_rotation_ba                                                 */
/*                                                                            */
/*   Finds the best rotation type for moving an element from stack B to A.    */
/*                                                                            */
/*   @param a: Pointer to stack A.                                            */
/*   @param b: Pointer to stack B.                                            */
/*   @return: The most efficient rotation type as an integer.                 */
/*                                                                            */
/* ************************************************************************** */
int	find_optimal_rotation_ba(t_stack *a, t_stack *b)
{
	t_stack	*current;
	int		best_rotation;
	int		(*cases[4])(t_stack *, t_stack *, int);

	cases[0] = case_rarb_a;
	cases[1] = case_rrarrb_a;
	cases[2] = case_rarrb_a;
	cases[3] = case_rrarb_a;
	best_rotation = case_rrarrb_a(a, b, b->nbr);
	current = b;
	while (current)
	{
		evaluate_rotation(a, b, current, &best_rotation, cases);
		current = current->next;
	}
	return (best_rotation);
}