/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:57:02 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/16 22:19:16 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*   push_element                                                             */
/*                                                                            */
/*   Pushes the top element of source stack onto destination stack.           */
/*                                                                            */
/*   @param dest: Pointer to destination stack.                               */
/*   @param src: Pointer to source stack.                                     */
/*                                                                            */
/* ************************************************************************** */
static void	push_element(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = *dest;
	*dest = *src;
	*src = (*src)->next;
	(*dest)->next = temp;
	if (*src)
		(*src)->prev = NULL;
	(*dest)->prev = NULL;
	if (temp)
		temp->prev = *dest;
}

/* ************************************************************************** */
/*   pa                                                                       */
/*                                                                            */
/*   Pushes the top element of stack B onto stack A.                          */
/*                                                                            */
/*   @param a: Pointer to stack A.                                            */
/*   @param b: Pointer to stack B.                                            */
/*   @param j: Flag to control output (0 prints "pa").                        */
/*                                                                            */
/* ************************************************************************** */
void	pa(t_stack **a, t_stack **b, int j)
{
	push_element(a, b);
	if (j == 0)
		ft_printf_fd(1, "pa\n");
}

/* ************************************************************************** */
/*   pb                                                                       */
/*                                                                            */
/*   Pushes the top element of stack A onto stack B.                          */
/*                                                                            */
/*   @param stack_a: Pointer to stack A.                                      */
/*   @param stack_b: Pointer to stack B.                                      */
/*   @param j: Flag to control output (0 prints "pb").                        */
/*                                                                            */
/* ************************************************************************** */
void	pb(t_stack **stack_a, t_stack **stack_b, int j)
{
	push_element(stack_b, stack_a);
	if (j == 0)
		ft_printf_fd(1, "pb\n");
}
