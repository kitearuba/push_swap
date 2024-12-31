/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:48 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/24 20:58:09 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Free all nodes in the stack and the stack itself.
 */
void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	ft_lstclear(&(stack->top), free);
	free(stack);
}

/**
 * Free both stacks, handling NULL safely.
 */
void	free_all_stacks(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}
