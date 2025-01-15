/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:17 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/15 20:16:00 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*   stack_free                                                               */
/*                                                                            */
/*   Frees all nodes in a stack and sets the stack pointer to NULL.           */
/*                                                                            */
/* ************************************************************************** */

void	stack_free(t_stack **stack)
{
	t_stack	*current;

	if (!stack || !*stack)
		return ;
	while (stack && *stack)
	{
		current = (*stack)->next;
		(*stack)->nbr = 0;
		free(*stack);
		*stack = current;
	}
	*stack = NULL;
}
