/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:32:55 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/12 03:26:00 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*   stack_new                                                                 */
/*                                                                            */
/*   Creates a new stack node with the given value.                           */
/*                                                                            */
/* ************************************************************************** */
t_stack	*stack_new(long value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		fatal_error();
	new_node->nbr = value;
	new_node->index = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
