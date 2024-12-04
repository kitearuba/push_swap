/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:23:10 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/27 22:32:52 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Find the minimum value in the stack
int find_min(t_stack *stack)
{
    t_list	*current;
    int		min;

    current = stack->top;
    min = *(int *)current->content;
    while (current)
    {
        if (*(int *)current->content < min)
            min = *(int *)current->content;
        current = current->next;
    }
    return (min);
}

int	find_max(t_stack *stack)
{
	t_list	*current;
	int		max;

	current = stack->top;
	max = *(int *)current->content;
	while (current)
	{
		if (*(int *) current->content > max)
			max = *(int *)current->content;
		current = current->next;
	}
	return (max);
}

// Find index of the target value in the stack
int find_index(t_stack *stack, int value)
{
	t_list	*current;
	int		index;

	current = stack->top;
	index = 0;
	while (current)
	{
		if (*(int *)current->content == value)
			return (index);
		current = current->next;
		index++;
	}
	return (-1); // Value not found
}