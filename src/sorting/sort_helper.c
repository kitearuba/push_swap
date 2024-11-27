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

#include "push_swap.h"

// Rotate optimally to the smallest element
static void	rotate_to_min(t_stack *a, int min_index)
{
	if (min_index <= a->size / 2)
	{
		while (min_index-- > 0)
			ra(a); // Rotate upwards
	}
	else
	{
		min_index = a->size - min_index;
		while (min_index-- > 0)
			rra(a); // Rotate downwards
	}
}

// Push the smallest element to stack B
void	push_min_to_b(t_stack *a, t_stack *b)
{
	t_list	*current;
	t_list	*min;
	int		index;
	int		min_index;

	current = a->top;
	min = current;
	index = 0;
	min_index = 0;
	while (current)
	{
		if (*(int *)current->content < *(int *)min->content)
		{
			min = current;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	rotate_to_min(a, min_index);
	pb(a, b); // Push the smallest element to B
}

// Move target value to the top of the stack
void move_to_top(t_stack *a, int value)
{
    int index = find_index(a, value);
    if (index < a->size / 2)
    {
        while (*(int *)a->top->content != value)
            ra(a); // Rotate stack to bring target to top
    }
    else
    {
        while (*(int *)a->top->content != value)
            rra(a); // Reverse rotate to bring target to top
    }
}
