/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_ba.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:53:10 by yogun             #+#    #+#             */
/*   Updated: 2022/08/09 11:23:11 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// This function calculates the required amount of rotation.
// Calculations are done for ra+rb case.
int	case_rarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = find_place_a(a, c);
	if (i < find_index(b, c))
		i = find_index(b, c);
	return (i);
}

// This function calculates the required amount of rotation.
// Calculations are done for rra+rrb case.
int	case_rrarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_place_a(a, c))
		i = stack_size(a) - find_place_a(a, c);
	if ((i < (stack_size(b) - find_index(b, c))) && find_index(b, c))
		i = stack_size(b) - find_index(b, c);
	return (i);
}

// This function calculates the required amount of rotation.
// Calculations are done for ra+rrb case.
int	case_rarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_index(b, c))
		i = stack_size(b) - find_index(b, c);
	i = find_place_a(a, c) + i;
	return (i);
}

// This function calculates the required amount of rotation.
// Calculations are done for rra+rb case.
int	case_rrarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_place_a(a, c))
		i = stack_size(a) - find_place_a(a, c);
	i = find_index(b, c) + i;
	return (i);
}
