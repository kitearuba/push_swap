#include "push_swap.h"

int	calculate_median(t_stack *stack)
{
    t_list	*current;
    int		*values;
    int		i = 0;

    if (stack->size == 0)
        return (0);
    values = malloc(sizeof(int) * stack->size);
    if (!values)
        fatal_error("Memory allocation failed", NULL);
    current = stack->top;
    while (current)
    {
        values[i++] = *(int *)current->content;
        current = current->next;
    }
    bubble_sort(values, stack->size); // Sort array using bubble sort
    int median = values[stack->size / 2];
    free(values);
    return (median);
}

void	bubble_sort(int *array, int size)
{
    int temp;
    int swapped;
    int i;

    swapped = 1;
    while (swapped)
    {
        swapped = 0;
        i = 0;
        while (i < size - 1)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
            i++;
        }
    }
}
