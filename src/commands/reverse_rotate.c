//
// Created by christian on 23/11/24.
//

#include "push_swap.h"

void rra(t_stack *a)
{
    if (a->size < 2)
        return;
    t_node *current = a->top;
    t_node *prev = NULL;

    // Traverse to the last node
    while (current && current->next)
    {
        prev = current;
        current = current->next;
    }

    // Move the last node to the top
    if (prev)
        prev->next = NULL;
    current->next = a->top;
    a->top = current;
}

void rrb(t_stack *b)
{
    rra(b); // Same logic as `rra` but applied to stack `b`
}

void rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
}
