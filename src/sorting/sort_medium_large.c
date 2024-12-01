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

int	should_rotate(t_stack *a, int min, int max)
{
	t_list	*current;
	int		index;
	int		size;

	current = a->top;
	index = 0;
	size = a->size;

	// Find the nearest index of an element within the range
	while (current)
	{
		if (*(int *)current->content >= min && *(int *)current->content <= max)
			break;
		current = current->next;
		index++;
	}

	// Rotate if it's closer to the top, otherwise reverse rotate
	return (index <= size / 2);
}


void	free_chunks(t_list **chunks, int chunk_count)
{
    int i;

    if (!chunks)
        return ;

    i = 0;
    while (i < chunk_count)
    {
        ft_lstclear(&chunks[i], free);
        i++;
    }
    free(chunks);
}

void	sort_and_push_chunks(t_list **chunks, int chunk_count, t_stack *a, t_stack *b)
{
    int	i;

    i = 0;
    while (i < chunk_count)
    {
        ft_printf("Before sorting chunk %d:\n", i + 1);
        print_chunk(chunks[i]);

        if (ft_lstsize(chunks[i]) <= 5)
            sort_small(a, b);
        else if (ft_lstsize(chunks[i]) <= 20)
            sort_medium(a, b);

        ft_printf("After sorting chunk %d:\n", i + 1);
        print_chunk(chunks[i]);
        i++;
    }
}

void	sort_medium_large(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	current_min;
	int	current_max;

	if (a->size <= 50)
		chunk_size = 5; // Smaller chunks for <= 50 elements
	else
		chunk_size = 10; // Larger chunks for > 50 elements

	current_min = find_min(a);

	while (has_values_in_range(a, current_min, current_min + chunk_size - 1))
	{
		current_max = current_min + chunk_size - 1;

		while (has_values_in_range(a, current_min, current_max))
		{
			if (*(int *)a->top->content >= current_min &&
			    *(int *)a->top->content <= current_max)
			{
				pb(a, b); // Push elements within range to B
			}
			else
			{
				if (should_rotate(a, current_min, current_max))
					ra(a); // Rotate A to bring element in range to top
				else
					rra(a); // Reverse rotate to bring element in range to top
			}
		}
		current_min = current_max + 1;
	}

	while (b->size > 0)
		pa(a, b); // Push all elements back to A
}