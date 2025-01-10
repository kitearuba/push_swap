/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:00:00 by user              #+#    #+#             */
/*   Updated: 2025/01/05 10:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// Execute a single operation on the stacks
void execute_operation(const char *operation, t_stack **a, t_stack **b)
{
    if (ft_strcmp(operation, "sa") == 0)
        sa(a, 0);
    else if (ft_strcmp(operation, "sb") == 0)
        sb(b, 0);
    else if (ft_strcmp(operation, "ss") == 0)
        ss(a, b, 0);
    else if (ft_strcmp(operation, "pa") == 0)
        pa(a, b, 0);
    else if (ft_strcmp(operation, "pb") == 0)
        pb(a, b, 0);
    else if (ft_strcmp(operation, "ra") == 0)
        ra(a, 0);
    else if (ft_strcmp(operation, "rb") == 0)
        rb(b, 0);
    else if (ft_strcmp(operation, "rr") == 0)
        rr(a, b, 0);
    else if (ft_strcmp(operation, "rra") == 0)
        rra(a, 0);
    else if (ft_strcmp(operation, "rrb") == 0)
        rrb(b, 0);
    else if (ft_strcmp(operation, "rrr") == 0)
        rrr(a, b, 0);
    else
        handle_error(a, b);
}

// Read operations from standard input and execute them
void read_operations(t_stack **a, t_stack **b)
{
    char *operation;

    while ((operation = get_next_line(STDIN_FILENO)) != NULL)
    {
        execute_operation(operation, a, b);
        free(operation);
    }
}

// Check if the stack is sorted and if stack B is empty
static int is_sorted_and_empty(t_stack *a, t_stack *b)
{
    if (b != NULL)
        return (0);
    while (a && a->next)
    {
        if (a->nbr > a->next->nbr)
            return (0);
        a = a->next;
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return (0);
    a = NULL;
    b = NULL;
    if (!parse_arguments(argc, argv, &a))
        handle_error(&a, &b);
    read_operations(&a, &b);
    if (is_sorted_and_empty(a, b))
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    stack_free(&a);
    stack_free(&b);
    return (0);
}