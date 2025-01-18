/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:57:02 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/18 12:11:23 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*   handle_reverse_operations                                                */
/*                                                                            */
/*   Executes reverse operations (rra, rrb, rrr) based on the input command.  */
/*                                                                            */
/*   @param a: Pointer to the first stack.                                    */
/*   @param b: Pointer to the second stack.                                   */
/*   @param read_line: Input command to process.                              */
/*   @return: None.                                                           */
/*                                                                            */
/* ************************************************************************** */
static void	handle_rr_operations(t_stack **a, t_stack **b, char *read_line)
{
	if (read_line[2] == 'a')
		rra(a, 1);
	else if (read_line[2] == 'b')
		rrb(b, 1);
	else if (read_line[2] == 'r')
		rrr(a, b, 1);
}

/* ************************************************************************** */
/*   process_command                                                          */
/*                                                                            */
/*   Executes stack operations based on the input command.                    */
/*   Handles errors for invalid commands.                                     */
/*                                                                            */
/*   @param read_line: Input command to process.                              */
/*   @param a: Pointer to the first stack.                                    */
/*   @param b: Pointer to the second stack.                                   */
/*   @return: A pointer to the next command read from standard input.         */
/*                                                                            */
/* ************************************************************************** */
static char	*process_command(char *read_line, t_stack **a, t_stack **b)
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
		handle_rr_operations(a, b, read_line);
	else if (read_line[0] == 'r' && read_line[1] == 'r' && read_line[2] == '\n')
		rr(a, b, 1);
	else if (read_line[0] == 's' && read_line[1] == 's' && read_line[2] == '\n')
		ss(a, b, 1);
	else
		handle_error(*a, *b);
	return (get_next_line(0));
}

/* ************************************************************************** */
/*   execute_checker_logic                                                    */
/*                                                                            */
/*   Reads and processes commands for stack operations.                       */
/*   Validates if the stack is sorted or not at the end.                      */
/*                                                                            */
/*   @param a: Pointer to the first stack.                                    */
/*   @param b: Pointer to the second stack.                                   */
/*   @param read_line: Initial input command read from standard input.        */
/*   @return: None.                                                           */
/*                                                                            */
/* ************************************************************************** */
static void	exe_checker_logic(t_stack **a, t_stack **b, char *read_line)
{
	char	*temp;

	while (read_line && *read_line != '\n')
	{
		temp = read_line;
		read_line = process_command(read_line, a, b);
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

/* ************************************************************************** */
/*   main                                                                     */
/*                                                                            */
/*   Entry point for the "checker" program.                                   */
/*   Validates arguments, processes commands, and outputs results.            */
/*                                                                            */
/*   @param argc: Argument count.                                             */
/*   @param argv: Argument vector.                                            */
/*   @return: 0 on successful execution.                                      */
/*                                                                            */
/* ************************************************************************** */
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
		exe_checker_logic(&a, &b, read_line);
	stack_free(&a);
	stack_free(&b);
	return (0);
}
