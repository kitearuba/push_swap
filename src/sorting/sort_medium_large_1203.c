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

t_list	**divide_into_chunks(t_stack *a, int chunk_size)
{
	t_list	**chunks;
	int		chunk_count;
	int		i;

	chunk_count = (a->size + chunk_size - 1) / chunk_size;
	chunks = malloc(sizeof(t_list *) * chunk_count);
	if (!chunks)
		return (NULL);
	i = 0;
	while (i < chunk_count)
	{
		chunks[i] = NULL;
		for (int j = 0; j < chunk_size && a->top; j++)
		{
			ft_lstadd_back(&chunks[i], ft_lstnew(a->top->content));
			a->top = a->top->next;
		}
		ft_printf("Chunk %d:\n", i + 1);
		print_chunk(chunks[i]);
		i++;
	}
	return (chunks);
}

void	sort_medium_large(t_stack *a, t_stack *b)
{
	int		chunk_size;
	t_list	**chunks;

    b->size = 0;
	if (!a || !a->top || a->size <= 0)
		return ;
	chunk_size = (a->size <= 50) ? (a->size / 5) : (a->size / 10);
	chunks = divide_into_chunks(a, chunk_size);
	if (!chunks)
		return ;
	// Free chunks after sorting logic
}



/*
int	find_next_max(t_stack *stack, int current_max)
{
	t_list	*current;
	int		next_max = find_min(stack);

	current = stack->top;
	while (current)
	{
		int value = *(int *)current->content;
		if (value < current_max && value > next_max)
			next_max = value;
		current = current->next;
	}
	return (next_max);
}

void	sort_stack_b(t_stack *b)
{
	int max_value;

	while (!is_sorted_descending(b))
	{
		max_value = find_max(b);

		// Move the largest value to the top of B
		move_to_top(b, max_value);

		// Swap if needed
		if (b->size > 1 && *(int *)b->top->content < *(int *)b->top->next->content)
			sb(b);
	}
}

int	is_sorted_descending(t_stack *stack)
{
	t_list	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (*(int *)current->content < *(int *)current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_medium_large(t_stack *a, t_stack *b)
{
	int current_max;
	// Initialize current_max to the largest value in A
	current_max = find_max(a);

	// Step 1: Place elements in order in A using B for assistance
	while (!is_sorted(a) || b->size > 0)
	{
		// Find the next maximum value in A
		int next_max = find_next_max(a, current_max);

		// Move the next maximum value to the top of A
		move_to_top(a, next_max);

		// If next_max is not in the correct order, push it to B
		if (*(int *)a->top->content != current_max - 1)
		{
			pb(a, b);
		}
		else
		{
			// If next_max is in order, update current_max and rotate A
			current_max = *(int *)a->top->content;
			ra(a);
		}

		// Sort B to place the pushed elements in descending order
		if (b->size > 1)
		{
			sort_stack_b(b);
		}
	}

	// Step 2: Push all elements back from B to A
	while (b->size > 0)
	{
		move_to_top(b, find_max(b)); // Bring the largest value in B to the top
		pa(a, b);                    // Push it back to A
	}
}
*/