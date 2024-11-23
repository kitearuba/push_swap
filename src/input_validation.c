/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:15 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/22 12:05:42 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_number(const char *str)
{
    if (*str == '-' || *str == '+') // Allow leading + or -
        str++;
    if (!*str) // Ensure there's at least one digit
        return (0);
    while (*str)
    {
        if (!isdigit(*str)) // Check if each character is a digit
            return (0);
        str++;
    }
    return (1);
}

int has_duplicates(t_stack *a)
{
    t_node *outer = a->top;
    t_node *inner;

    while (outer)
    {
        inner = outer->next;
        while (inner)
        {
            if (outer->value == inner->value)
                return (1); // Duplicate found
            inner = inner->next;
        }
        outer = outer->next;
    }
    return (0); // No duplicates
}

int parse_arguments(int argc, char **argv, t_stack *a)
{
    int	value;
	int	i;

    i = 0;
    while (i < argc) // Skip the program name
    {
        if (!is_number(argv[i])) // Validate input
        {
            write(2, "Error: Invalid number\n", 22);
            return (0);
        }
        value = ft_atoi(argv[i]); // Convert string to integer
        push(a, value); // Push value onto Stack A
        i++;
    }
    if (has_duplicates(a)) // Check for duplicates
    {
        write(2, "Error: Duplicates found\n", 24);
        return (0);
    }
    return (1); // Success
}
