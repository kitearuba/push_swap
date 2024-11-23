/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:53:01 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/23 19:48:22 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ; // Exit if the stack is already sorted
	if (a->size <= 5)
		sort_small(a);
	else if (a->size <= 100)
		sort_medium(a, b);
	else
		sort_large(a, b);
}
