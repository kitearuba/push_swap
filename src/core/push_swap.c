/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:53:01 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/27 17:19:17 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sort the stack using appropriate methods based on its size.
 */
void	push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a) == 1)
		return ;
	else
	{
		if (a->size <= 5)
			sort_small(a, b);
		else if (a->size <= 40)
			sort_medium(a, b);
		else
			sort_medium_large(a, b);
	}
}