//
// Created by christian on 23/11/24.
//

#include "push_swap.h"

void ra(t_stack *a)
{
    if (a->size < 2)
        return;
    int value = pop(a); // Remove the top element
    t_node *current = a->top;

    // Traverse to the last node
    while (current && current->next)
        current = current->next;

    // Create a new node and link it to the end
    t_node *new_node = malloc(sizeof(t_node));
    new_node->value = value;
    new_node->next = NULL;
    current->next = new_node;
    a->size++;
}

void rb(t_stack *b)
{
    ra(b); // Same logic as `ra` but applied to stack `b`
}

void rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
}
