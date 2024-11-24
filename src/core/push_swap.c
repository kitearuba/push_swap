/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:53:01 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/24 20:58:35 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sort the stack using appropriate methods based on its size.
 */
void	push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size <= 5)
		sort_small(a);
	else if (a->size <= 100)
		sort_medium(a, b);
	else
		sort_large(a, b);
}
