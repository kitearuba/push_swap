/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:48 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/23 19:07:19 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Free all lists in the stack and the stack itself.
 */
void	free_stack(t_stack *stack)
{
	if (stack)
	{
    		ft_lstclear(&(stack->top), free); // Use ft_lstclear for the list
    		free(stack); // Free the stack structure itself
	}
}

/**
 * Free multiple stacks, handling NULL safely.
 */
void	free_all_stacks(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}
