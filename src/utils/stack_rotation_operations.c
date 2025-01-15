/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotation_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:58:33 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/15 22:35:17 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*   rotate_both_forward                                                      */
/*                                                                            */
/*   Rotates both stacks A and B in the same direction as required and moves  */
/*   the target number.                                                       */
/* ************************************************************************** */
int	ra_rb(t_stack **a, t_stack **b, int target, char stack_type)
{
	if (stack_type == 'a')
	{
		while ((*a)->nbr != target && determine_position_in_b(*b, target) > 0)
			rr(a, b, 0);
		while ((*a)->nbr != target)
			ra(a, 0);
		while (determine_position_in_b(*b, target) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->nbr != target && determine_position_in_a(*a, target) > 0)
			rr(a, b, 0);
		while ((*b)->nbr != target)
			rb(b, 0);
		while (determine_position_in_a(*a, target) > 0)
			ra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

/* ************************************************************************** */
/*   rotate_both_reverse                                                      */
/*                                                                            */
/*   Rotates both stacks A and B in the reverse direction as required and     */
/*   moves the target number.                                                 */
/* ************************************************************************** */
int	rra_rrb(t_stack **a, t_stack **b, int target, char stack_type)
{
	if (stack_type == 'a')
	{
		while ((*a)->nbr != target && determine_position_in_b(*b, target) > 0)
			rrr(a, b, 0);
		while ((*a)->nbr != target)
			rra(a, 0);
		while (determine_position_in_b(*b, target) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->nbr != target && determine_position_in_a(*a, target) > 0)
			rrr(a, b, 0);
		while ((*b)->nbr != target)
			rrb(b, 0);
		while (determine_position_in_a(*a, target) > 0)
			rra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

/* ************************************************************************** */
/*   rotate_a_reverse_b_forward                                               */
/*  																		  */
/*   Rotates stack A in reverse and stack B in the forward direction, then    */
/*   moves the target number.                                                 */
/* ************************************************************************** */
int	rra_rb(t_stack **a, t_stack **b, int target, char stack_type)
{
	if (stack_type == 'a')
	{
		while ((*a)->nbr != target)
			rra(a, 0);
		while (determine_position_in_b(*b, target) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (determine_position_in_a(*a, target) > 0)
			rra(a, 0);
		while ((*b)->nbr != target)
			rb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}

/* ************************************************************************** */
/*   rotate_a_forward_b_reverse                                               */
/*                                                                            */
/*   Rotates stack B in reverse and stack A in the forward direction, then    */
/*   moves the target number.                                                 */
/* ************************************************************************** */
int	ra_rrb(t_stack **a, t_stack **b, int target, char stack_type)
{
	if (stack_type == 'a')
	{
		while ((*a)->nbr != target)
			ra(a, 0);
		while (determine_position_in_b(*b, target) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (determine_position_in_a(*a, target) > 0)
			ra(a, 0);
		while ((*b)->nbr != target)
			rrb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}
