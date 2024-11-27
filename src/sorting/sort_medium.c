
#include "push_swap.h"

static void move_min_to_b(t_stack *a, t_stack *b)
{
    int min_value;

    while (a->size > 0)
    {
        min_value = find_min(a);
        move_to_top(a, min_value); // Bring the minimum value to the top
        pb(a, b);                  // Push it to stack B
    }
}

static void restore_stack_a(t_stack *a, t_stack *b)
{
    while (b->size > 0)
        pa(a, b); // Push back all elements to stack A
}

static void insertion_sort(t_stack *a, t_stack *b)
{
    move_min_to_b(a, b);
    restore_stack_a(a, b);
}

static void sort_chunks(t_stack *a, t_stack *b, int chunk_size)
{
    int start;
    int end;

    start = find_min(a);
    while (start <= find_max(a))
    {
        end = start + chunk_size - 1;
        while (has_values_in_range(a, start, end))
        {
            int target = find_closest_target(a, start, end);
            move_to_top(a, target); // Rotate the target to the top
            pb(a, b);               // Push to stack B
        }
        start = end + 1;
    }
}

static void reintegrate_stack(t_stack *a, t_stack *b)
{
    while (b->size > 0)
    {
        int max = find_max(b);
        move_to_top(b, max); // Move the largest element in B to the top
        pa(a, b);            // Push it back to A
    }
}

void sort_medium(t_stack *a, t_stack *b)
{
    int chunk_size;

    if (a->size <= 20)
        insertion_sort(a, b);
    else
    {
        chunk_size = calculate_chunk_size(a->size);
        sort_chunks(a, b, chunk_size);
        restore_stack_a(a, b);
    }
}
