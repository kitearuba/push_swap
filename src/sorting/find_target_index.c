#include "push_swap.h"

int	find_target_index(t_stack *stack, int target)
{
    t_list	*current;
    int		index = 0;

    current = stack->top;
    while (current)
    {
        if (*(int *)current->content == target)
            return (index);
        current = current->next;
        index++;
    }
    return (-1); // Target not found
}

int	find_min_index(t_stack *stack)
{
    t_list	*current;
    int		min;
    int		index = 0;
    int		min_index = 0;

    if (!stack || !stack->top)
        return (-1);
    current = stack->top;
    min = *(int *)current->content;
    while (current)
    {
        if (*(int *)current->content < min)
        {
            min = *(int *)current->content;
            min_index = index;
        }
        current = current->next;
        index++;
    }
    return (min_index);
}

int	find_max_index(t_stack *stack)
{
    t_list	*current;
    int		max;
    int		index = 0;
    int		max_index = 0;

    if (!stack || !stack->top)
        return (-1);
    current = stack->top;
    max = *(int *)current->content;
    while (current)
    {
        if (*(int *)current->content > max)
        {
            max = *(int *)current->content;
            max_index = index;
        }
        current = current->next;
        index++;
    }
    return (max_index);
}
