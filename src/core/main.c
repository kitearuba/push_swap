/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:36 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/23 19:22:16 by chrrodri         ###   ########.fr       */
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
	fatal_error("Failed to create stack A", NULL);
    b = create_stack(); // Create Stack B
    if (!b)
	error_handle("Failed to create stack B", a, NULL);
    if (!parse_arguments(argc - 1, argv + 1, a) == -1) // Parse args  
	error_handle("Invalid input", a, b);	
    push_swap(a, b);
    clean_all(a, b);	
    return (0);
}
