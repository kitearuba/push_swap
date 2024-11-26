#include "push_swap.h"

int calculate_median(t_stack *stack)
{
    t_list *current = stack->top;
    int *values;
    int size = stack->size;
    int median;

    if (size <= 0)
        return 0;
    values = malloc(sizeof(int) * size);
    if (!values)
        fatal_error("Memory allocation failed", stack);
    for (int i = 0; current; current = current->next, i++)
        values[i] = *(int *)current->content;

    quicksort(values, 0, size - 1); // Assume this is implemented elsewhere
    median = values[size / 2];
    free(values);
    return median;
}

int find_max_index(t_stack *stack)
{
    t_list *current = stack->top;
    int max_value = *(int *)current->content;
    int max_index = 0;
    int index = 0;

    while (current)
    {
        if (*(int *)current->content > max_value)
        {
            max_value = *(int *)current->content;
            max_index = index;
        }
        current = current->next;
        index++;
    }
    return max_index;
}

int find_min_index(t_stack *stack)
{
    t_list *current = stack->top;
    int min_value = *(int *)current->content;
    int min_index = 0;
    int index = 0;

    while (current)
    {
        if (*(int *)current->content < min_value)
        {
            min_value = *(int *)current->content;
            min_index = index;
        }
        current = current->next;
        index++;
    }
    return min_index;
}
