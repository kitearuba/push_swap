/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:17 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/09 11:50:13 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                          Sorting Large Stacks                              */
/* ************************************************************************** */

static void	push_to_b_till_3(t_stack **a, t_stack **b)
{
	int		rotate_type;
	t_stack	*tmp;

	while (stack_size(*a) > 3 && !is_sorted(*a))
	{
		tmp = *a;
		rotate_type = rotate_type_ab(*a, *b);
		while (rotate_type >= 0)
		{
			if (rotate_type == case_rarb(*a, *b, tmp->nbr))
				rotate_type = apply_rarb(a, b, tmp->nbr, 'a');
			else if (rotate_type == case_rrarrb(*a, *b, tmp->nbr))
				rotate_type = apply_rrarrb(a, b, tmp->nbr, 'a');
			else if (rotate_type == case_rarrb(*a, *b, tmp->nbr))
				rotate_type = apply_rarrb(a, b, tmp->nbr, 'a');
			else if (rotate_type == case_rrarb(*a, *b, tmp->nbr))
				rotate_type = apply_rrarb(a, b, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
}

t_stack	*sort_b(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	pb(a, &b, 0);
	if (stack_size(*a) > 3 && !is_sorted(*a))
		pb(a, &b, 0);
	if (stack_size(*a) > 3 && !is_sorted(*a))
		push_to_b_till_3(a, &b);
	if (!is_sorted(*a))
		sort_three(a);
	return (b);
}

// Push elements back from stack_b to stack_a while maintaining order.
t_stack	**push_back_to_a(t_stack **a, t_stack **b)
{
	int		rotate_type;
	t_stack	*tmp;

	while (*b)
	{
		tmp = *b;
		rotate_type = rotate_type_ba(*a, *b);
		while (rotate_type >= 0)
		{
			if (rotate_type == case_rarb_a(*a, *b, tmp->nbr))
				rotate_type = apply_rarb(a, b, tmp->nbr, 'b');
			else if (rotate_type == case_rarrb_a(*a, *b, tmp->nbr))
				rotate_type = apply_rarrb(a, b, tmp->nbr, 'b');
			else if (rotate_type == case_rrarrb_a(*a, *b, tmp->nbr))
				rotate_type = apply_rrarrb(a, b, tmp->nbr, 'b');
			else if (rotate_type == case_rrarb_a(*a, *b, tmp->nbr))
				rotate_type = apply_rrarb(a, b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (a);
}

// Main function to sort large stacks using push_swap logic.
void	sort_big(t_stack **a)
{
	t_stack	*b;
	int		rotate_type;

	b = sort_b(a);
	a = push_back_to_a(a, &b);
	rotate_type = find_index(*a, ft_min(*a));
	if (rotate_type < stack_size(*a) - rotate_type)
	{
		while ((*a)->nbr != ft_min(*a))
			ra(a, 0);
	}
	else
	{
		while ((*a)->nbr != ft_min(*a))
			rra(a, 0);
	}
}
