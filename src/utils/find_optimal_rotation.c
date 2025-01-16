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
/*   find_optimal_rotation_ab                                                 */
/*                                                                            */
/*   Finds the best rotation type for moving an element from stack A to B.    */
/*                                                                            */
/*   @return: The most efficient rotation type as an integer.                 */
/*                                                                            */
/* ************************************************************************** */
int	find_optimal_rotation_ab(t_stack *a, t_stack *b)
{
	long	best_rotation;
	t_stack	*node;

	node = a;
	best_rotation = MAX_INT;
	while (node)
	{
		if (best_rotation > calculate_ra_rb(a, b, node->nbr))
			best_rotation = calculate_ra_rb(a, b, node->nbr);
		if (best_rotation > calculate_rra_rrb(a, b, node->nbr))
			best_rotation = calculate_rra_rrb(a, b, node->nbr);
		if (best_rotation > calculate_ra_rrb(a, b, node->nbr))
			best_rotation = calculate_ra_rrb(a, b, node->nbr);
		if (best_rotation > calculate_rra_rb(a, b, node->nbr))
			best_rotation = calculate_rra_rb(a, b, node->nbr);
		node = node->next;
	}
	return (best_rotation);
}

/* ************************************************************************** */
/*                                                                            */
/*   find_optimal_rotation_ba                                                 */
/*                                                                            */
/*   Finds the best rotation type for moving an element from stack B to A.    */
/*                                                                            */
/*   @return: The most efficient rotation type as an integer.                 */
/*                                                                            */
/* ************************************************************************** */
int	find_optimal_rotation_ba(t_stack *a, t_stack *b)
{
	int		best_rotation;
	t_stack	*node;

	node = b;
	best_rotation = MAX_INT;
	while (node)
	{
		if (best_rotation > calculate_rotations_ba(a, b, node->nbr))
			best_rotation = calculate_rotations_ba(a, b, node->nbr);
		if (best_rotation > calculate_rr_b_and_a(a, b, node->nbr))
			best_rotation = calculate_rr_b_and_a(a, b, node->nbr);
		if (best_rotation > calculate_rrb_and_ra(a, b, node->nbr))
			best_rotation = calculate_rrb_and_ra(a, b, node->nbr);
		if (best_rotation > calculate_rb_and_rra(a, b, node->nbr))
			best_rotation = calculate_rb_and_rra(a, b, node->nbr);
		node = node->next;
	}
	return (best_rotation);
}
