#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return (0);
    a = parse_arguments(argc, argv);
    b = create_stack(a->size);
    push_swap(a, b);
    free_stack(a);
    free_stack(b);
    return (0);
}
