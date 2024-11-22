#include "push_swap.h"

void push_swap(t_stack *a, t_stack *b)
{
    if (a->size <= 5)
        sort_small(a);
    else if (a->size <= 100)
        sort_medium(a, b);
    else
        sort_large(a, b);
}