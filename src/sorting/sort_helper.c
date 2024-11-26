#include "push_swap.h"

int find_min(t_stack *stack)
{
	t_list	*current;
	int		min_value;

	if (!stack || !stack->top)
		return (-1); // Return an invalid value if the stack is empty
	current = stack->top;
	min_value = *(int *)current->content;
	while (current)
	{
		if (*(int *)current->content < min_value)
			min_value = *(int *)current->content;
		current = current->next;
	}
	return (min_value);
}

int find_max(t_stack *stack)
{
	t_list	*current;
	int		max_value;

	if (!stack || !stack->top)
		return (-1); // Return an invalid value if the stack is empty
	current = stack->top;
	max_value = *(int *)current->content;
	while (current)
	{
		if (*(int *)current->content > max_value)
			max_value = *(int *)current->content;
		current = current->next;
	}
	return (max_value);
}

int find_max_index(t_stack *stack)
{
	t_list	*current;
	int		max_index = 0;
	int		max_value;
	int		index = 0;

	if (!stack || !stack->top)
		return (-1);
	current = stack->top;
	max_value = *(int *)current->content;
	while (current)
	{
		if (*(int *)current->content > max_value)
		{
			max_value = *(int *)current->content;
			max_index = index;
		}
		index++;
		current = current->next;
	}
	return (max_index);
}
