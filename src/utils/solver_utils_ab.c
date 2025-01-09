/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:41:10 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/08 21:30:17 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// This function calculates how many times 
// we should rotate the stacks together.
// Because after a certain amoun of rotate, we will
// proceed only with one stack rotation.
int	case_rarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = find_place_b(b, c);
	if (i < find_index(a, c))
		i = find_index(a, c);
	return (i);
}

// This function calculates how many times we should rotate the stacks together.
// Because after a certain amoun of rotate, we will proceed only with one stack
// rotation. Since here we have reverse rotate,rather than index number,
// we check reverse index number which is 
// calculated by list_size - index_number.
int	case_rrarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_place_b(b, c))
		i = stack_size(b) - find_place_b(b, c);
	if ((i < (stack_size(a) - find_index(a, c))) && find_index(a, c))
		i = stack_size(a) - find_index(a, c);
	return (i);
}

// Again, this function makes similar calculations.
// This function do same calculations for rra+rb case.
int	case_rrarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_index(a, c))
		i = stack_size(a) - find_index(a, c);
	i = find_place_b(b, c) + i;
	return (i);
}

// Again, this function makes similar calculations.
// This function do same calculations for ra+rrb case.
int	case_rarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_place_b(b, c))
		i = stack_size(b) - find_place_b(b, c);
	i = find_index(a, c) + i;
	return (i);
}
