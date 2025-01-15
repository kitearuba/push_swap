/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optimal_rotation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:41:10 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/15 19:45:47 by chrrodri         ###   ########.fr       */
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

	cases[0] = calculate_ra_rb;
	cases[1] = calculate_rra_rrb;
	cases[2] = calculate_ra_rrb;
	cases[3] = calculate_rra_rb;
	best_rotation = calculate_rra_rrb(a, b, a->nbr);
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

	cases[0] = calculate_rotations_ba;
	cases[1] = calculate_rr_b_and_a;
	cases[2] = calculate_rrb_and_ra;
	cases[3] = calculate_rb_and_rra;
	best_rotation = calculate_rr_b_and_a(a, b, b->nbr);
	current = b;
	while (current)
	{
		evaluate_rotation(a, b, current, &best_rotation, cases);
		current = current->next;
	}
	return (best_rotation);
}
