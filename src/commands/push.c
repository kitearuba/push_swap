/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:57:02 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/23 21:44:20 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Push the top element of stack b to stack a
voidrst	pa(t_stack *a, t_stack *b)
{
	t_list	*first;

	if (b->size == 0)
		return ;
	first = b->top;
	b->top = a->top;
	a->top = first;
}

void pb(t_stack *a, t_stack *b)
{
    pa(b, a); // Reverse the logic of `pa`
}
