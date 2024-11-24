/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:57:02 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/24 01:23:03 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Push the top element of stack b to stack a
void	pa(t_stack *a, t_stack *b)
{
	push_node(b, a);
}

void	pb(t_stack *a, t_stack *b)
{
	push_node(a, b);
}
