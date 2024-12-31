//
// Created by christian on 31/12/24.
//
void free_all_stacks(t_stack *a, t_stack *b)
{
    if (a)
        free_stack(a);
    if (b)
        free_stack(b);
}
