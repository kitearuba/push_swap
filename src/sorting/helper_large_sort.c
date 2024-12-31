/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_large_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:23:10 by chrrodri          #+#    #+#             */
/*   Updated: 2024/12/31 00:08:52 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

size_t list_size(t_stack *stack)
{
    return stack->size;
}
int	error_handle(const char *error_message, t_stack *a, t_stack *b)
{
	clean_all (a, b);
	fatal_error(error_message, NULL);
	return (1);
}

int find_stack_index(t_stack *stack, int value)
{
    t_list *current;
    int index = 0;

    current = stack->top;
    while (current)
    {
        if (*(int *)current->content == value)
            return index;
        index++;
        current = current->next;
    }
    return -1; // Not found
}

int find_insert_pos(t_stack *stack, int value)
{
    t_list *current = stack->top;
    int position = 0;

    while (current && current->next)
    {
        if (value > *(int *)current->content && value < *(int *)current->next->content)
            return position + 1;
        position++;
        current = current->next;
    }

    // Handle smallest or largest case
    if (value < *(int *)stack->top->content || value > *(int *)current->content)
        return 0;

    return position + 1;
}

