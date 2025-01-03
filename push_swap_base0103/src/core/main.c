/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:36 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/25 18:33:21 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = create_stack();
	if (!a)
		fatal_error("Failed to create stack A", NULL);
	b = create_stack();
	if (!b)
		handle_error("Failed to create stack B", a, NULL);
	if (parse_arguments(argc - 1, argv + 1, a) == -1)
		handle_error("Invalid input", a, b);
	push_swap(a, b);
	free_all_stacks(a, b);
	return (0);
}
