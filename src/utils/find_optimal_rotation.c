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
/*   @param a: Pointer to stack A.                                            */
/*   @param b: Pointer to stack B.                                            */
/*   @return: The most efficient rotation type as an integer.                 */
/*                                                                            */
/* ************************************************************************** */
int	find_optimal_rotation_ab(t_stack *a, t_stack *b)
{
	long	best_rotation;
	t_stack	*current;

	current = a;
	best_rotation = calculate_rra_rrb(a, b, a->nbr);
	while (current)
	{
		if (best_rotation > calculate_ra_rb(a, b, current->nbr))
			best_rotation = calculate_ra_rb(a, b, current->nbr);
		if (best_rotation > calculate_rra_rrb(a, b, current->nbr))
			best_rotation = calculate_rra_rrb(a, b, current->nbr);
		if (best_rotation > calculate_ra_rrb(a, b, current->nbr))
			best_rotation = calculate_ra_rrb(a, b, current->nbr);
		if (best_rotation > calculate_rra_rb(a, b, current->nbr))
			best_rotation = calculate_rra_rb(a, b, current->nbr);
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
	int		best_rotation;
	t_stack	*current;

	current = b;
	best_rotation = calculate_rr_b_and_a(a, b, b->nbr);
	while (current)
	{
		if (best_rotation > calculate_rotations_ba(a, b, current->nbr))
			best_rotation = calculate_rotations_ba(a, b, current->nbr);
		if (best_rotation > calculate_rr_b_and_a(a, b, current->nbr))
			best_rotation = calculate_rr_b_and_a(a, b, current->nbr);
		if (best_rotation > calculate_rrb_and_ra(a, b, current->nbr))
			best_rotation = calculate_rrb_and_ra(a, b, current->nbr);
		if (best_rotation > calculate_rb_and_rra(a, b, current->nbr))
			best_rotation = calculate_rb_and_rra(a, b, current->nbr);
		current = current->next;
	}
	return (best_rotation);
}
