/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:36 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/22 11:52:39 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return (0); // Exit if no arguments are provided
    a = create_stack(); // Create Stack A
    if (!a)
        return (1); // Exit if memory allocation fails
    b = create_stack(); // Create Stack B
    if (!b)
    {
        free_stack(a);
        return (1); // Exit if memory allocation fails
    }
    if (!parse_arguments(argc, argv, a)) // Parse input and push to stack A
    {
        free_stack(a);
        free_stack(b);
        return (1); // Exit if parsing fails
    }
    push_swap(a, b); // Perform sorting
    free_stack(a); // Clean up
    free_stack(b);
    return (0);
}
