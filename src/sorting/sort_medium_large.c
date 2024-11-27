/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_large.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:15:04 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/27 19:42:45 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_chunks(t_stack *a, t_stack *b, int chunk_size)
{
	int	start;
	int	end;

	start = find_min(a);
	while (start <= find_max(a))
	{
		while
		{
			
		}
	}
}
// Main sorting function for medium_large-sized inputs
void	sort_medium_large(t_stack *a, t_stack *b)
{
	int	chunck_size;
if

	if (a->size <=50)
		chunk_size = size / 5;else
	else
		chunk_size = size / 10;
	sort_chunks(a, b, chunk_size);
	restore_stack_a(a, b);
}
