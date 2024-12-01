/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_large.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:15:04 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/27 22:14:37 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_chunk(t_list *chunk)
{
	while (chunk)
	{
		ft_printf("%d ", *(int *)chunk->content);
		chunk = chunk->next;
	}
	ft_printf("\n");
}

t_list	**divide_into_chunks(t_stack *a, int divisor)
{
	t_list	**chunks;
	int		chunk_size;
	int		chunk_count;
	int		i;
	int		j;

	if (!a || divisor <= 0)
		return (NULL);

	chunk_size = a->size / divisor;
	if (chunk_size < 1)
		chunk_size = 1;

	chunk_count = (a->size + chunk_size - 1) / chunk_size;

	chunks = malloc(sizeof(t_list *) * chunk_count);
	if (!chunks)
		return (NULL);

	i = 0;
	while (i < chunk_count)
	{
		chunks[i] = NULL;
		j = 0;
		while (j < chunk_size && a->top)
		{
			ft_lstadd_back(&chunks[i], ft_lstnew(a->top->content));
			a->top = a->top->next;
			j++;
		}
		ft_printf("Chunk %d:\n", i + 1);
		print_chunk(chunks[i]);
		i++;
	}
	return (chunks);
}

void	sort_medium_large(t_stack *a)
{
	int	divisor;

	if (!a || !a->top || a->size <= 0)
		return ;

	if (a->size <= 50)
		divisor = 5;
	else
		divisor = 10;

	divide_into_chunks(a, divisor);
}
