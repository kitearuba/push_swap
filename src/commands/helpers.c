/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:04:10 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/24 21:14:03 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Swap the top two elements of the stack.
 */
void	swap_top_two(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	void	*tmp;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	tmp = first->content;
	first->content = second->content;
	second->content = tmp;
}

/**
 * Push the top element from one stack to another.
 */
void	push_node(t_stack *from, t_stack *to)
{
	t_list	*node;

	if (from->size == 0)
		return ;
	node = from->top;
	from->top = node->next;
	node->next = to->top;
	to->top = node;
	from->size--;
	to->size++;
}

/**
 * Rotate the stack: move the top element to the bottom.
 */
void	rotate_stack(t_stack *stack)
{
	t_list	*first;

	if (stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	ft_lstadd_back(&(stack->top), first);
}

/**
 * Reverse rotate the stack: move the bottom element to the top.
 */
void	reverse_rotate_stack(t_stack *stack)
{
	t_list	*previous;
	t_list	*current;

	if (stack->size < 2)
		return ;
	previous = NULL;
	current = stack->top;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	if (previous)
		previous->next = NULL;
	ft_lstadd_front(&(stack->top), current);
}
