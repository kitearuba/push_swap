/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:15 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/23 19:44:50 by chrrodri         ###   ########.fr       */
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
		if (!ft_isdigit(*str))
		return (0);
		str++;
	}
	return (1);
}

int has_duplicates(t_stack *a)
{
	t_list	*outer;
	t_list	*inner;

	outer = a->top;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if ((int *)outer->value == (int *)inner->value)
				return (1); // Duplicate found
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (0); // No duplicates
}	

int parse_arguments(int argc, char **argv, t_stack *a)
{
	int	i;
	int	*value;

	i = 0;
	while (i < argc) // Skip the program name
	{
		if (!is_number(argv[i])) // Validate input
			return (fatal_error("Error: Invalid number", NULL), 0);
		*value = ft_atoi(argv[i]); // Convert string to integer
		ft_lstadd_back(&(a->top), ft_lstnew(value));
		a->size++;
		i++;
	}
	if (has_duplicates(a)) // Check for duplicates
		return (fatal_error("Error: Duplicate found", NULL), 0)
	return (1); // Success
}
