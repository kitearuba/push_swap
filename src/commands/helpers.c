/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:04:10 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/24 01:14:33 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_two(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	void	*tmp;

	if (stack < 2)
		return ;
	first = stack->top;
	second = first->next;
	tmp = first->content;
	first->content = second->content;
	second->content = tmp;
}

void	push_node(t_stack *from, t_stack *to)
{
	t_list	*node;

	if (from->size == 0)
		return ;
	node = from->top;
	from->top = to->top;
	to->top = node;
	from->size--;
	to->size++;void
}

void	rotate_stack(t_stack stack)
{
	t_list	*first;

	if (stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next; //Update stack top to second element
	first->next = NULL; // Detach first element
	ft_lstadd_back(stack->top, first); //Add it to the end
}

void	reverse_rotate_stack(t_stack *stack)
{
	t_list	*previous;
	t_list	*current;

	previous = NULL;
	current = stack->top;
	if (stack < 2)
		return ;
	while (current->next)
	{
		previous = current;
		current = current->next;
		previous->next = NULL;
		ft_lstadd_front(&(stack->top), current);
	}
}
