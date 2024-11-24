/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:57:55 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/24 21:11:56 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	swap_top_two(a);
}

void	sb(t_stack *b)
{
	swap_top_two(b);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_top_two(a);
	swap_top_two(b);
}
