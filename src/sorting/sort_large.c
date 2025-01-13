/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:17 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/12 04:30:00 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*   push_initial_elements_to_b                                               */
/*                                                                            */
/*   Pushes the first two elements from stack A to stack B.                   */
/*                                                                            */
/*   @param stack_a: Pointer to stack A.                                      */
/*   @param stack_b: Pointer to stack B.                                      */
/*                                                                            */
/* ************************************************************************** */
static void	push_initial_elements_to_b(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b, 0);
	if (get_stack_size(*stack_a) > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*   optimize_and_push_to_b                                                   */
/*                                                                            */
/*   Pushes elements from stack A to stack B using optimized rotations.       */
/*                                                                            */
/*   @param stack_a: Pointer to stack A.                                      */
/*   @param stack_b: Pointer to stack B.                                      */
/*                                                                            */
/* ************************************************************************** */
static void	optimize_and_push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		rotation_case;
	t_stack	*current_node;

	while (get_stack_size(*stack_a) > 3 && !is_sorted(*stack_a))
	{
		current_node = *stack_a;
		rotation_case = find_optimal_rotation_ab(*stack_a, *stack_b);
		while (rotation_case >= 0)
		{
			if (rotation_case == calculate_rotations_ab(*stack_a, *stack_b, current_node->nbr))
				rotation_case = rotate_both_forward(stack_a, stack_b, current_node->nbr, 'a');
			else if (rotation_case == calculate_rr_a_and_b(*stack_a, *stack_b, current_node->nbr))
				rotation_case = rotate_both_reverse(stack_a, stack_b, current_node->nbr, 'a');
			else if (rotation_case == calculate_ra_and_rrb(*stack_a, *stack_b, current_node->nbr))
				rotation_case = rotate_a_forward_b_reverse(stack_a, stack_b, current_node->nbr, 'a');
			else if (rotation_case == calculate_rra_and_rb(*stack_a, *stack_b, current_node->nbr))
				rotation_case = rotate_a_reverse_b_forward(stack_a, stack_b, current_node->nbr, 'a');
			else
				current_node = current_node->next;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*   reduce_stack_a_to_three                                                  */
/*                                                                            */
/*   Reduces stack A to three elements by pushing elements to stack B.        */
/*                                                                            */
/*   @param stack_a: Pointer to stack A.                                      */
/*   @param stack_b: Pointer to stack B.                                      */
/*                                                                            */
/* ************************************************************************** */
static void	reduce_stack_a_to_three(t_stack **stack_a, t_stack **stack_b)
{
	push_initial_elements_to_b(stack_a, stack_b);
	optimize_and_push_to_b(stack_a, stack_b);
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
}


/* ************************************************************************** */
/*                                                                            */
/*   move_elements_to_a                                                       */
/*                                                                            */
/*   Moves elements from stack B back to stack A in sorted order.             */
/*                                                                            */
/* ************************************************************************** */
static t_stack	**move_elements_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		rotation_case;
	t_stack	*node_to_process;

	while (*stack_b)
	{
		node_to_process = *stack_b;
		rotation_case = find_optimal_rotation_ba(*stack_a, *stack_b);
		while (rotation_case >= 0)
		{
			if (rotation_case == calculate_rotations_ba(*stack_a, *stack_b, node_to_process->nbr))
				rotation_case = rotate_both_forward(stack_a, stack_b, node_to_process->nbr, 'b');
			else if (rotation_case == calculate_rrb_and_ra(*stack_a, *stack_b, node_to_process->nbr))
				rotation_case = rotate_both_reverse(stack_a, stack_b, node_to_process->nbr, 'b');
			else if (rotation_case == calculate_rr_b_and_a(*stack_a, *stack_b, node_to_process->nbr))
				rotation_case = rotate_a_forward_b_reverse(stack_a, stack_b, node_to_process->nbr, 'b');
			else if (rotation_case == calculate_rb_and_rra(*stack_a, *stack_b, node_to_process->nbr))
				rotation_case = rotate_a_reverse_b_forward(stack_a, stack_b, node_to_process->nbr, 'b');
			else
				node_to_process = node_to_process->next;
		}
	}
	return (stack_a);
}

/* ************************************************************************** */
/*                                                                            */
/*   sort_large_stack                                                         */
/*                                                                            */
/*   Main function to sort large stacks.                                      */
/*   - Pushes elements to stack B.                                            */
/*   - Moves elements back to stack A.                                        */
/*   - Rotates stack A to bring the smallest element to the top.              */
/*                                                                            */
/* ************************************************************************** */
void	sort_large(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		min_index;

	stack_b = NULL;
	reduce_stack_a_to_three(stack_a, &stack_b);
	stack_a = move_elements_to_a(stack_a, &stack_b);
	min_index = find_index_in_stack(*stack_a, find_min_value(*stack_a));
	if (min_index < get_stack_size(*stack_a) - min_index)
	{
		while ((*stack_a)->nbr != find_min_value(*stack_a))
			ra(stack_a, 0);
	}
	else
	{
		while ((*stack_a)->nbr != find_min_value(*stack_a))
			rra(stack_a, 0);
	}
}