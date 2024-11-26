#include "push_swap.h"

int find_min(t_stack *stack)
{
    t_node *current;
    int min_value;

    if (!stack || !stack->top)
        return (INT_MAX); // Return INT_MAX if the stack is empty

    current = stack->top;
    min_value = current->value;

    while (current)
    {
        if (current->value < min_value)
            min_value = current->value;
        current = current->next;
    }
    return (min_value);
}

int find_max(t_stack *stack)
{
    t_node *current;
    int max_value;

    if (!stack || !stack->top)
        return (INT_MIN); // Return INT_MIN if the stack is empty

    current = stack->top;
    max_value = current->value;

    while (current)
    {
        if (current->value > max_value)
            max_value = current->value;
        current = current->next;
    }
    return (max_value);
}

int find_max_index(t_stack *stack)
{
    t_node *current;
    int max_index = 0;
    int max_value;
    int index = 0;

    if (!stack || !stack->top)
        return (-1); // Return -1 if the stack is empty

    current = stack->top;
    max_value = current->value;

    while (current)
    {
        if (current->value > max_value)
        {
            max_value = current->value;
            max_index = index;
        }
        index++;
        current = current->next;
    }
    return (max_index);
}