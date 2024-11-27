
#include "push_swap.h"

int has_values_in_range(t_stack *a, int start, int end)
{
    t_list *current;

    current = a->top;
    while (current)
    {
        if (*(int *)current->content >= start && *(int *)current->content <= end)
            return (1);
        current = current->next;
    }
    return (0);
}

int find_next_target_in_range(t_stack *a, int start, int end)
{
    t_list *current;

    current = a->top;
    while (current)
    {
        if (*(int *)current->content >= start && *(int *)current->content <= end)
            return (*(int *)current->content);
        current = current->next;
    }
    return (start); // Fallback
}

int find_max(t_stack *stack)
{
    t_list *current;
    int max;

    if (!stack || !stack->top)
        return (0); // Handle empty stack case

    current = stack->top;
    max = *(int *)current->content;
    while (current)
    {
        if (*(int *)current->content > max)
            max = *(int *)current->content;
        current = current->next;
    }
    return (max);
}

int    calculate_chunk_size(int size)
{
    if (size <= 50)
        return (size / 5); // Divide into 5 chunks for smaller inputs
    else
        return (size / 10); // Divide into 10 chunks for larger inputs
}

void move_to_top(t_stack *stack, int value)
{
    int index;
    int size;

    index = find_index(stack, value); // Find the index of the value
    size = stack->size;

    if (index == -1) // Value not found
        return;

    if (index <= size / 2)
    {
        while (*(int *)stack->top->content != value)
            ra(stack); // Rotate stack upwards
    }
    else
    {
        while (*(int *)stack->top->content != value)
            rra(stack); // Rotate stack downwards
    }
}

// Find the closest target (top or bottom) in the given range
int find_closest_target(t_stack *a, int start, int end)
{
    t_list *current = a->top;
    int top_index = 0;
    int bottom_index = a->size - 1;
    int value_top = -1;
    int value_bottom = -1;

    // Scan from the top
    while (current)
    {
        int value = *(int *)current->content;
        if (value >= start && value <= end)
        {
            value_top = value;
            break;
        }
        top_index++;
        current = current->next;
    }

    // Scan from the bottom
    current = a->top;
    while (bottom_index > top_index)
    {
        if (*(int *)current->content >= start && *(int *)current->content <= end)
        {
            value_bottom = *(int *)current->content;
        }
        bottom_index--;
        current = current->next;
    }

    // Return the closer target
    return (top_index <= (a->size - bottom_index)) ? value_top : value_bottom;
}
