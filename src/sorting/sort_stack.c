/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:53:01 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/04 22:39:42 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                          Stack Sorting Dispatcher                          */
/* ************************************************************************** */

/**
 * sort_stack - Sorts a given stack using the appropriate sorting algorithm.
 * @a: Pointer to stack A.
 * @b: Pointer to stack B.
 * Description:
 * - Dispatches to `sort_small` for stacks up to 5 elements.
 * - Dispatches to `sort_big` for stacks larger than 5 elements.
 */
void sort_stack(t_stack *a)
{
	if (!a || stack_size(a)  == 0  || is_sorted(a))
		return ;
	else if (stack_size(a) <= 5)
		sort_small(&a);
	else
		sort_big(&a);
}
