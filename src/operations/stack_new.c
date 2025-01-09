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
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if (!node)
        fatal_error();
    node->nbr = value;
    node->index = -1; // Initialize the index as unassigned
    node->next = NULL;
    node->prev = NULL;
    return (node);
}
