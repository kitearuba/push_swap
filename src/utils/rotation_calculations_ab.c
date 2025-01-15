/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_calculations_ab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:41:10 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/15 22:54:32 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*   calculate_joint_rotations_ab                                             */
/*                                                                            */
/*   Calculates the number of rotations required for both stacks (ra + rb).   */
/*   Ensures that the rotation count is optimal for moving an element.        */
/*                                                                            */
/*   @param target_value: The value to evaluate for optimal rotations.        */
/*   @return: The total number of joint rotations required.                   */
/*                                                                            */
/* ************************************************************************** */

int	calculate_ra_rb(t_stack *a, t_stack *b, int target_value)
{
	int	rotations_a;
	int	rotations_b;

	rotations_a = find_index_in_stack(a, target_value);
	rotations_b = determine_position_in_b(b, target_value);
	if (rotations_b < rotations_a)
		return (rotations_a);
	return (rotations_b);
}

/* ************************************************************************** */
/*   calculate_joint_reverse_rotations_ab                                     */
/*                                                                            */
/*   Calculates the number of reverse rotations required for both stacks      */
/*   (rra + rrb). Determines the optimal rotation count for moving elements.  */
/*                                                                            */
/*   @param target_value: The value to evaluate for optimal rotations.        */
/*   @return: The total number of joint reverse rotations required.           */
/*                                                                            */
/* ************************************************************************** */

int	calculate_rra_rrb(t_stack *a, t_stack *b, int target_value)
{
	int	rotations_a;
	int	rotations_b;

	rotations_a = 0;
	rotations_b = 0;
	if (determine_position_in_b(b, target_value))
		rotations_b = get_stack_size(b) - determine_position_in_b
			(b, target_value);
	if (find_index_in_stack(a, target_value))
		rotations_a = get_stack_size(a) - find_index_in_stack(a, target_value);
	if (rotations_b < rotations_a)
		return (rotations_a);
	return (rotations_b);
}

/* ************************************************************************** */
/*   calculate_reverse_rotate_and_rotate_ab                                   */
/*                                                                            */
/*   Calculates the number of rotations required for stack A to reverse       */
/*   (rra) and stack B to rotate (rb) for optimal sorting.                    */
/*                                                                            */
/*   @param target_value: The value to evaluate for optimal rotations.        */
/*   @return: The total number of rotations required.                         */
/*                                                                            */
/* ************************************************************************** */

int	calculate_rra_rb(t_stack *stack_a, t_stack *stack_b, int target_value)
{
	int	rotations_a;
	int	rotations_b;

	rotations_a = 0;
	if (find_index_in_stack(stack_a, target_value))
		rotations_a = get_stack_size(stack_a) - find_index_in_stack
			(stack_a, target_value);
	rotations_b = determine_position_in_b(stack_b, target_value);
	return (rotations_a + rotations_b);
}

/* ************************************************************************** */
/*   calculate_rotate_and_reverse_rotate_ab                                   */
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

int	calculate_ra_rrb(t_stack *stack_a, t_stack *stack_b, int target_value)
{
	int	rotations_a;
	int	rotations_b;

	rotations_b = 0;
	if (determine_position_in_b(stack_b, target_value))
		rotations_b = get_stack_size(stack_b) - determine_position_in_b
			(stack_b, target_value);
	rotations_a = find_index_in_stack(stack_a, target_value);
	return (rotations_a + rotations_b);
}
