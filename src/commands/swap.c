/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:57:55 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/23 20:04:55 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	t_list	*first;
	t_list	*second;
	void	*tmp;

	if (a->size < 2)
		return ;
	first = a->top;
	second = first->next;
	// Swap the content pointers
	tmp = first->content;
	first->content = second->content;
	second->content = tmp;
}

void	sb(t_stack *b)
{
	t_list	*first;
	t_list	*second;
	void	*tmp;

	if (b-> size < 2)
		return ;
	first = b->top;
	second = first->next;
	// Swap content
	tmp = first->content;
	first->content = second->content;
	second->content = tmp;
}

void	ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}
