#include "push_swap.h"

int find_target_index(t_stack *stack, int value)
{
    t_list *current = stack->top;
    int index = 0;

    while (current)
    {
        if (*(int *)current->content == value)
            return index;
        current = current->next;
        index++;
    }
    return -1; // Return -1 if the value is not found
}

int find_max(t_stack *stack)
{
    t_list *current = stack->top;
    int max_value = *(int *)current->content;

    while (current)
    {
        if (*(int *)current->content > max_value)
            max_value = *(int *)current->content;
        current = current->next;
    }
    return max_value;
}

int find_min(t_stack *stack)
{
    t_list *current = stack->top;
    int min_value = *(int *)current->content;

    while (current)
    {
        if (*(int *)current->content < min_value)
            min_value = *(int *)current->content;
        current = current->next;
    }
    return min_value;
}
