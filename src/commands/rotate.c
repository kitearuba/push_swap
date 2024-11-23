/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:57:21 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/23 21:33:10 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	t_list	*first;

	if (a->size < 2)
		return ;
	first = a->top;
	a->top = first->next; //Update top to the second element
	first->next = NULL; // Deatch first element
	ft_lstadd_back(&(a->top), first); // Add it to the end
}

void rb(t_stack *b)
{
	t_list	*first;

	if (b->size < 2)
		return ;
	first = b->top;
	b->top = first->next;
	first->next = NULL;
	ft_lstadd_back(&(b->top), first);
}

void rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
}
