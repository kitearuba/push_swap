
#include "push_swap.h"

// Find index of a target value in the stack
int find_index(t_stack *stack, int value)
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
    return -1; // Value not found
}

// Find minimum value in the stack
int find_min(t_stack *stack)
{
    t_list *current = stack->top;
    int min = *(int *)current->content;

    while (current)
    {
        if (*(int *)current->content < min)
            min = *(int *)current->content;
        current = current->next;
    }
    return min;
}
