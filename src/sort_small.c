#include "push_swap.h"

void sort_small(t_stack *a)
{
    if (a->arr[0] > a->arr[1])
        sa(a);
    if (a->arr[0] > a->arr[2])
        rra(a);
    if (a->arr[1] > a->arr[2])
        sa(a);
}
