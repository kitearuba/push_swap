/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:53:01 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/15 18:23:52 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*   sort_stack                                                               */
/*                                                                            */
/*   Sorts a given stack using the appropriate sorting algorithm based on     */
/*   the size of the stack.                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_stack(t_stack **a)
{
	if (get_stack_size(*a) == 2)
		sa(a, 0);
	else if (get_stack_size(*a) == 3)
		sort_three(a);
	else
		sort_large(a);
}
