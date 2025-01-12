/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:01:48 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/10 22:36:56 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// Function to add a new node to the stack from back side
void	stack_add_back(t_stack **stack, t_stack *new)
{
    t_stack	*last;

    if (!stack || !new)
        return ;
    if (*stack)
    {
        last = get_last_node(*stack);
        last->next = new;
    }
    else
        *stack = new;
}
