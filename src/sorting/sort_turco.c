/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turco.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:28 by chrrodri          #+#    #+#             */
/*   Updated: 2024/12/16 20:03:48 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_turco(t_stack *a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
	while (a->size > 3)
	{
		int	rotate_up;
		int	rotate_down;

		rotate_up = 0;
		rotate_down = 0;
		if (b->size = 2 && a->top > b->top && a->top < b
	}
}
