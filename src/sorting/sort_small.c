/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:37 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/12 01:32:00 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

/* ************************************************************************** */
/*   move_to_top                                                              */
/*                                                                            */
/*   Rotates the stack to bring the element at the specified index to the     */
/*   top efficiently.                                                         */
/*                                                                            */
/* ************************************************************************** */
static void	move_to_top(t_stack **stack, int index)
{
	int	size;
	int	rotations;

	size = stack_size(*stack);
	if (size == 0 || index < 0 || index >= size)
		return ;
	if (index <= size / 2)
	{
		rotations = index;
		while (rotations-- > 0)
			ra(stack, 0);
	}
	else
	{
		rotations = size - index;
		while (rotations-- > 0)
			rra(stack, 0);
	}
}

/* ************************************************************************** */
/*   push_smallest_to_b                                                       */
/*                                                                            */
/*   Finds the smallest element in stack A, moves it to the top, and pushes   */
/*   it to stack B.                                                           */
/*                                                                            */
/* ************************************************************************** */
static void	push_smallest_to_b(t_stack **a, t_stack **b)
{
	int	smallest_index;

	smallest_index = find_index(*a, ft_min(*a));
	move_to_top(a, smallest_index);
	pb(a, b, 0);
}

/* ************************************************************************** */
/*   sort_small                                                               */
/*                                                                            */
/*   Sorts a stack of up to five elements by using stack B for temporary      */
/*   storage.                                                                 */
/*                                                                            */
/* ************************************************************************** */
void	sort_small(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (stack_size(*a) == 2)
	{
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a, 0);
		return ;
	}
	if (stack_size(*a) <= 3)
	{
		sort_three(a);
		return ;
	}
	while (stack_size(*a) > 3)
		push_smallest_to_b(a, &b);
	sort_three(a);
	while (b)
		pa(a, &b, 0);
}