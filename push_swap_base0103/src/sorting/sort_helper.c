/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:23:20 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/27 17:46:44 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_stack *a)
{
	int		first;
	int		second;
	int		third;

	first = *(int *)a->top->content;
	second = *(int *)a->top->next->content;
	third = *(int *)a->top->next->next->content;

	if (first > second && second > third)
	{
		// Case: 3 2 1
		sa(a);
		rra(a);
	}
	else if (first > third && third > second)
		ra(a); // Case: 3 1 2
	else if (second > first && first > third)
		rra(a); // Case: 2 3 1
	else if (second > third && third > first)
	{
		// Case: 1 3 2
		sa(a);
		ra(a);
	}
	else if (third > first && first > second)
		sa(a); // Case: 2 1 3
}

void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = find_index(a, find_min(a));
	if (min_index <= a->size / 2)
	{
		while (min_index > 0)
		{
			ra(a);
			min_index--;
		}
	}
	else
	{
		while (min_index < a->size)
		{
			rra(a);
			min_index++;
		}
	}
	pb(a, b);
}

void move_to_top(t_stack *stack, int index)
{
    if (index <= stack->size / 2)
    {
        while (index-- > 0)
            ra(stack);
    }
    else
    {
        index = stack->size - index;
        while (index-- > 0)
            rra(stack);
    }
}


