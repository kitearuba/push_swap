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

// This function is the second part of the ft_check function.
static void	ft_check_sub(t_stack **a, t_stack **b, char *read_line)
{
    if (read_line[2] == 'a')
        rra(a, 1);
    else if (read_line[2] == 'b')
        rrb(b, 1);
    else if (read_line[2] == 'r')
        rrr(a, b, 1);
}

// Execute a single read_line on the stacks
static char    *execute_read_line(char *read_line, t_stack **a, t_stack **b)
{
    if (read_line[0] == 's' && read_line[1] == 'a' && read_line[2] == '\n')
        sa(a, 1);
    else if (read_line[0] == 's' && read_line[1] == 'b' && read_line[2] == '\n')
        sb(b, 1);
    else if (read_line[0] == 'p' && read_line[1] == 'a' && read_line[2] == '\n')
        pa(a, b, 1);
    else if (read_line[0] == 'p' && read_line[1] == 'b' && read_line[2] == '\n')
        pb(a, b, 1);
    else if (read_line[0] == 'r' && read_line[1] == 'a' && read_line[2] == '\n')
        ra(a, 1);
    else if (read_line[0] == 'r' && read_line[1] == 'b' && read_line[2] == '\n')
        rb(b, 1);
    else if (read_line[0] == 'r' && read_line[1] == 'r' && read_line[3] == '\n')
        ft_check_sub(a, b, read_line);
    else if (read_line[0] == 'r' && read_line[1] == 'r' && read_line[2] == '\n')
        rr(a, b, 1);
    else if (read_line[0] == 's' && read_line[1] == 's' && read_line[2] == '\n')
        ss(a, b, 1);
    else
        handle_error(*a, *b);
    return (get_next_line(0));
}

// This function checks the validity of the commands and stack.
// If it is valid, and the stack_a is sorted, the program prints "OK".
static void	ft_checker_sub(t_stack **a, t_stack **b, char *read_line)
{
	char	*temp;

	while (read_line && *read_line != '\n')
	{
		temp = read_line;
		read_line = execute_read_line(read_line, a, b);
		free(temp);
	}
	if (*b)
		ft_printf_fd(1 ,"KO\n");
	else if (!is_sorted(*a))
		ft_printf_fd(1, "KO\n");
	else
		ft_printf_fd(1, "OK\n");
	free(read_line);
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    char *read_line;

    if (argc < 2)
        return (0);
    a = validate_arguments(argc, argv);
	b = NULL;
    read_line = get_next_line(0);
    if (!read_line && !is_sorted(a))
        ft_printf_fd(STDOUT_FILENO, "KO\n");
    else if (!read_line && is_sorted(a))
        ft_printf_fd(STDOUT_FILENO, "OK\n");
    else
		ft_checker_sub(&a, &b, read_line);
    stack_free(&a);
    stack_free(&b);
    return (0);
}