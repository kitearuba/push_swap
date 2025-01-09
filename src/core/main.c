/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:36 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/05 22:37:42 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;

    if (argc < 2)
        return (0);
    a = NULL;
    parse_arguments(argc, argv, &a);
    if (is_sorted(a))
        fatal_error();
    has_duplicates(a);
    sort_stack(a);
    stack_free(&a);
    return (0);
}
