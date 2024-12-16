/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turco.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:28 by chrrodri          #+#    #+#             */
/*   Updated: 2024/12/16 20:31:33 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_turco(t_stack *a, t_stack *b)
{
	int	rotate_up;
	int	rotate_down;
	
	pb(a, b);
	pb(a, b);
	rotate_up = 0;
	rotate_down = 0;
	if (b->size == 2)
	{
		if (b->top > b->top->next && a->top > b->top)
			pb(a, b)
		else if (a->top < b->top && a->top > b->top->next)
		{
			rb(b);
			pb(a, b);
		}
		else
		{
			rrb(b);
			pb(a, b);
		}
	}
}
