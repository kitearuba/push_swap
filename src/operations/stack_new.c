/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:32:55 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/23 16:56:25 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// Function to create a new stack node
t_stack *stack_new(long value)
{
    t_stack *new_node;

    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        fatal_error();
    new_node->nbr = value;
    new_node->index = -1; // Initialize the index as unassigned
    new_node->next = NULL;
    new_node->prev = NULL;
    return (new_node);
}