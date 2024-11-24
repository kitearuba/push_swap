//
// Created by christian on 23/11/24.
//

#include "push_swap.h"

void rra(t_stack *a)
{
	reverse_rotate_stack(a);
}

void rrb(t_stack *b)
{
	reverse_rotate_stack(b);
}

void rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
}
