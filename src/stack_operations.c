#include "stack.h"
#include <stdlib.h>

t_stack *create_stack(int size)
{
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->arr = malloc(size * sizeof(int));
    if (!stack->arr)
    {
        free(stack);
        return (NULL);
    }
    stack->size = size;
    stack->top = -1;
    return (stack);
}

void push(t_stack *stack, int value)
{
    if (stack->top < stack->size - 1)
        stack->arr[++stack->top] = value;
}

int pop(t_stack *stack)
{
    if (stack->top >= 0)
        return (stack->arr[stack->top--]);
    return (-1);
}

void free_stack(t_stack *stack)
{
    free(stack->arr);
    free(stack);
}
