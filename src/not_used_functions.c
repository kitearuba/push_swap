//
// Created by christian on 3/12/24.
//

// sort_helper

void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min;
	int	index;

	min = find_min(a);
	index = find_index(a, min);

	if (index <= a->size / 2)
	{
		while (*(int *)a->top->content != min)
			ra(a); // Rotate forward if the element is closer to the top
	}
	else
	{
		while (*(int *)a->top->content != min)
			rra(a); // Reverse rotate if the element is closer to the bottom
	}
	pb(a, b); // Push the smallest element to stack B
}






void	reintegrate_chunks_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		int max_value = find_max(b);
		move_to_top(b, max_value);
		pa(a, b); // Push the largest value from B to A
	}
}

//FIND_TARGET_INDEX.C


// Find the next target value in the current chunk
int find_next_target(t_stack *a, int chunk_size, int index)
{
	t_list *current = a->top;
	int min = find_min(a);
	int max = min + chunk_size * (index + 1);

	while (current)
	{
		int value = *(int *)current->content;
		if (value >= min && value <= max)
			return value;
		current = current->next;
	}
	return min; // Fallback to the minimum if no value is found
}



//medium_large


void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = find_index(a, find_min(a));
	if (min_index <= a->size / 2)
	{
		while (min_index > 0)
		{
			ra(a);
			min_index--;
		}
	}
	else
	{
		while (min_index < a->size)
		{
			rra(a);
			min_index++;
		}
	}
	pb(a, b);
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