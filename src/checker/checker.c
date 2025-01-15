/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:57:02 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/15 18:04:28 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_check_sub(t_stack **a, t_stack **b, char *read_line)
{
	if (read_line[2] == 'a')
		rra(a, 1);
	else if (read_line[2] == 'b')
		rrb(b, 1);
	else if (read_line[2] == 'r')
		rrr(a, b, 1);
}

static char	*execute_read_line(char *read_line, t_stack **a, t_stack **b)
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
		ft_printf_fd(1, "KO\n");
	else if (!is_sorted(*a))
		ft_printf_fd(1, "KO\n");
	else
		ft_printf_fd(1, "OK\n");
	free(read_line);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*read_line;

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
