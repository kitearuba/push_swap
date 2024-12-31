/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:15 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/25 18:41:59 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_number(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	has_duplicates(t_stack *a)
{
	t_list	*outer;
	t_list	*inner;

	outer = a->top;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (*(int *)outer->content == *(int *)inner->content)
				return (1);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (0);
}

int	parse_arguments(int argc, char **argv, t_stack *a)
{
	int		i;
	int		*value;

	i = 0;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			handle_error("Error: Invalid number", a, NULL);
		value = malloc(sizeof(int));
		if (!value)
			handle_error("Error: Memory allocation failed", a, NULL);
		*value = ft_atoi(argv[i]);
		ft_lstadd_back(&(a->top), ft_lstnew(value));
		a->size++;
		i++;
	}
	if (has_duplicates(a))
		handle_error("Error: Duplicate found", a, NULL);
	return (1);
}
