/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:53:01 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/25 19:29:28 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sort the stack using appropriate methods based on its size.
 */
void	push_swap(t_stack *a, t_stack *b)
{
	ft_printf("Check one push_swap\n");
	if (is_sorted(a) == 0)
	{
		ft_printf("Check 1 push_swap\n");
		return ;
	}
	else
	{
		ft_printf("Check 2 push_swap\n");
		if (a->size <= 5)
		{
			ft_printf("Check two push_swap\n");
			sort_small(a, b);
		}
		else if (a->size <= 100)
			sort_medium(a, b);
		else
			sort_large(a, b);
	}
	ft_printf("Check three push_swap\n");
}
