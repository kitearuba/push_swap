/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:57:21 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/25 20:29:43 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_stack *a)
{
	rotate_stack(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	rotate_stack(b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_printf("rr\n");
}
