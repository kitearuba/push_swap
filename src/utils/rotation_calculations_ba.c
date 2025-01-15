/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_calculations_ba.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:36 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/15 22:55:31 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*   calculate_joint_rotations_ba                                             */
/*                                                                            */
/*   Calculates the number of rotations required for both stacks (ra + rb)    */
/*   when moving an element from stack B to stack A.                          */
/*                                                                            */
/*   @param stack_a: Pointer to stack A.                                      */
/*   @param stack_b: Pointer to stack B.                                      */
/*   @param target_value: The value to evaluate for optimal rotations.        */
/*   @return: The total number of joint rotations required.                   */
/*                                                                            */
/* ************************************************************************** */

int	calculate_rotations_ba(t_stack *a, t_stack *b, int target_value)
{
	int	rotations_a;
	int	rotations_b;

	rotations_a = determine_position_in_a(a, target_value);
	rotations_b = find_index_in_stack(b, target_value);
	if (rotations_b > rotations_a)
		return (rotations_b);
	return (rotations_a);
}

/* ************************************************************************** */
/*   calculate_joint_reverse_rotations_ba                                     */
/*                                                                            */
/*   Calculates the number of reverse rotations required for both stacks      */
/*   (rra + rrb) when moving an element from stack B to stack A.              */
/*                                                                            */
/*   @param stack_a: Pointer to stack A.                                      */
/*   @param stack_b: Pointer to stack B.                                      */
/*   @param target_value: The value to evaluate for optimal rotations.        */
/*   @return: The total number of joint reverse rotations required.           */
/*                                                                            */
/* ************************************************************************** */

int	calculate_rr_b_and_a(t_stack *stack_a, t_stack *stack_b, int target_value)
{
	int	rotations_a;
	int	rotations_b;

	rotations_a = get_stack_size(stack_a) - determine_position_in_a
		(stack_a, target_value);
	rotations_b = get_stack_size(stack_b) - find_index_in_stack
		(stack_b, target_value);
	if (rotations_b > rotations_a)
		return (rotations_b);
	return (rotations_a);
}

/* ************************************************************************** */
/*   calculate_reverse_rotate_and_rotate_ba                                   */
/*                                                                            */
/*   Calculates the number of rotations required for stack A to reverse       */
/*   (rra) and stack B to rotate (rb) for optimal sorting.                    */
/*                                                                            */
/*   @param stack_a: Pointer to stack A.                                      */
/*   @param stack_b: Pointer to stack B.                                      */
/*   @param target_value: The value to evaluate for optimal rotations.        */
/*   @return: The total number of rotations required.                         */
/*                                                                            */
/* ************************************************************************** */

int	calculate_rrb_and_ra(t_stack *a, t_stack *b, int target_value)
{
	int	rotations_a;
	int	rotations_b;

	rotations_a = determine_position_in_a(a, target_value);
	rotations_b = get_stack_size(b) - find_index_in_stack(b, target_value);
	return (rotations_a + rotations_b);
}

/* ************************************************************************** */
/*   calculate_rotate_and_reverse_rotate_ba                                   */
/*                                                                            */
/*   Calculates the number of rotations required for stack A to rotate        */
/*   (ra) and stack B to reverse (rrb) for optimal sorting.                   */
/*                                                                            */
/*   @param stack_a: Pointer to stack A.                                      */
/*   @param stack_b: Pointer to stack B.                                      */
/*   @param target_value: The value to evaluate for optimal rotations.        */
/*   @return: The total number of rotations required.                         */
/*                                                                            */
/* ************************************************************************** */

int	calculate_rb_and_rra(t_stack *a, t_stack *b, int target_value)
{
	int	rotations_a;
	int	rotations_b;

	rotations_a = get_stack_size(a) - determine_position_in_a
		(a, target_value);
	rotations_b = find_index_in_stack(b, target_value);
	return (rotations_a + rotations_b);
}
