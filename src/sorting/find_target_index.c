#include "push_swap.h"

int	find_target_index(t_stack *a, int low, int high)
{
	t_list	*current;
	int		index;

	current = a->top;
	index = 0;
	while (current)
	{
		if (*(int *)current->content >= low && *(int *)current->content <= high)
			return (index);
		current = current->next;
		index++;
	}
	return (-1); // No element found
}
