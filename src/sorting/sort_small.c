/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:37 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/27 17:46:58 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (*(int *)a->top->content > *(int *)a->top->next->content)
			sa(a);
		return ;
	}
	if (a->size == 3)
	{
		sort_three(a);
		return ;
	}
	while (a->size > 3)
		push_smallest_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
