/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:59:46 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/22 12:18:52 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error_exit(const char *message)
{
    write(2, message,ft_strlen(message));
    exit(EXIT_FAILURE);
}

int is_sorted(t_stack *a)
{
    t_node *current = a->top;

    while (current && current->next)
    {
        if (current->value > current->next->value)
            return (0); // Not sorted
        current = current->next;
    }
    return (1); // Sorted
}
