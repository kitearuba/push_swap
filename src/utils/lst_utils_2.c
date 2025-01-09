/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:41:10 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/05 21:30:17 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// This function checks the index of a number
// 	 in the stack.
int	find_index(t_stack *a, int nbr)
{
	int		i;

	i = 0;
	while (a->nbr != nbr)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}

// This function finds the correct place of the number in stack_b.
// In other words, it check what index number nbr_push will get 
// after it is being pushed to the stack_b.
int	find_place_b(t_stack *b, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push > b->nbr && nbr_push < stack_last(b)->nbr)
		i = 0;
	else if (nbr_push > ft_max(b) || nbr_push < ft_min(b))
		i = find_index(b, ft_max(b));
	else
	{
		tmp = b->next;
		while (b->nbr < nbr_push || tmp->nbr > nbr_push)
		{
			b = b->next;
			tmp = b->next;
			i++;
		}
	}
	return (i);
}

// This function finds the correct place of the number in stack_a.
// In other words, it check what index number nbr_push will get 
// after it is being pushed to the stack_a.
int	find_place_a(t_stack *a, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push < a->nbr && nbr_push > stack_last(a)->nbr)
		i = 0;
	else if (nbr_push > ft_max(a) || nbr_push < ft_min(a))
		i = find_index(a, ft_min(a));
	else
	{
		tmp = a->next;
		while (a->nbr > nbr_push || tmp->nbr < nbr_push)
		{
			a = a->next;
			tmp = a->next;
			i++;
		}
	}
	return (i);
}
