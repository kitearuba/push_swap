/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:17 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/15 19:35:04 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*   push_initial_elements_to_b                                               */
/*                                                                            */
/*   Pushes the first two elements from stack A to stack B.                   */
/*                                                                            */
/*   @param a: Pointer to stack A.                                      */
/*   @param b: Pointer to stack B.                                      */
/*                                                                            */
/* ************************************************************************** */
static void	push_initial_elements_to_b(t_stack **a, t_stack **b)
{
	pb(a, b, 0);
	if (get_stack_size(*a) > 3 && !is_sorted(*a))
		pb(a, b, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*   optimize_and_push_to_b                                                   */
/*                                                                            */
/*   Pushes elements from stack A to stack B using optimized rotations.       */
/*                                                                            */
/*   @param a: Pointer to stack A.                                            */
/*   @param b: Pointer to stack B.                                            */
/*                                                                            */
/* ************************************************************************** */
static void	optimize_and_push_to_b(t_stack **a, t_stack **b)
{
	int		r_case;
	t_stack	*node;

	while (get_stack_size(*a) > 3 && !is_sorted(*a))
	{
		node = *a;
		r_case = find_optimal_rotation_ab(*a, *b);
		while (r_case >= 0)
		{
			if (r_case == calculate_ra_rb(*a, *b, node->nbr))
				r_case = ra_rb(a, b, node->nbr, 'a');
			else if (r_case == calculate_rra_rrb(*a, *b, node->nbr))
				r_case = rra_rrb(a, b, node->nbr, 'a');
			else if (r_case == calculate_ra_rrb(*a, *b, node->nbr))
				r_case = ra_rrb(a, b, node->nbr, 'a');
			else if (r_case == calculate_rra_rb(*a, *b, node->nbr))
				r_case = rra_rb(a, b, node->nbr, 'a');
			else
				node = node->next;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*   reduce_stack_a_to_three                                                  */
/*                                                                            */
/*   Reduces stack A to three elements by pushing elements to stack B.        */
/*                                                                            */
/* ************************************************************************** */
static void	reduce_stack_a_to_three(t_stack **a, t_stack **b)
{
	push_initial_elements_to_b(a, b);
	optimize_and_push_to_b(a, b);
	if (!is_sorted(*a))
		sort_three(a);
}

/* ************************************************************************** */
/*                                                                            */
/*   move_elements_to_a                                                       */
/*                                                                            */
/*   Moves elements from stack B back to stack A in sorted order.             */
/*                                                                            */
/* ************************************************************************** */
static void	move_elements_to_a(t_stack **a, t_stack **b)
{
	int		r_case;
	t_stack	*node;

	while (*b)
	{
		node = *b;
		r_case = find_optimal_rotation_ba(*a, *b);
		while (r_case >= 0)
		{
			if (r_case == calculate_rotations_ba(*a, *b, node->nbr))
				r_case = ra_rb(a, b, node->nbr, 'b');
			else if (r_case == calculate_rrb_and_ra(*a, *b, node->nbr))
				r_case = rra_rrb(a, b, node->nbr, 'b');
			else if (r_case == calculate_rr_b_and_a(*a, *b, node->nbr))
				r_case = ra_rrb(a, b, node->nbr, 'b');
			else if (r_case == calculate_rb_and_rra(*a, *b, node->nbr))
				r_case = rra_rb(a, b, node->nbr, 'b');
			else
				node = node->next;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*   sort_large                                                               */
/*                                                                            */
/*   Main function to sort large stacks.                                      */
/*   - Pushes elements to stack B.                                            */
/*   - Moves elements back to stack A.                                        */
/*   - Rotates stack A to bring the smallest element to the top.              */
/*                                                                            */
/* ************************************************************************** */
void	sort_large(t_stack **a)
{
	t_stack	*b;
	int		min_index;

	b = NULL;
	reduce_stack_a_to_three(a, &b);
	move_elements_to_a(a, &b);
	min_index = find_index_in_stack(*a, find_min_value(*a));
	if (min_index < get_stack_size(*a) - min_index)
		while ((*a)->nbr != find_min_value(*a))
			ra(a, 0);
	else
		while ((*a)->nbr != find_min_value(*a))
			rra(a, 0);
}
