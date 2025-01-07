#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                      Rotate Type Decision Logic                            */
/* ************************************************************************** */

/**
 * rotate_type_ab - Determines the type of rotation for stack A.
 * @a: Pointer to stack A.
 * @b: Pointer to stack B.
 * Description:
 * - Calculates the most efficient rotation type (ra, rra, etc.)
 *   for moving an element from A to B.
 * Return: Rotation type as an integer or enum.
 */
int rotate_type_ab(t_stack *a, t_stack *b)
{
    int min_index;
    int max_index;
    int target_index;

    target_index = find_optimal_rotation(a, b);
    min_index = find_min_index(a);
    max_index = find_max_index(a);

    if (target_index < (a->size / 2))
        return (ROTATE_RA);
    else if (target_index >= (a->size / 2))
        return (ROTATE_RRA);
    return (ROTATE_DEFAULT); // Default fallback
}

/**
 * rotate_type_ba - Determines the type of rotation for stack B.
 * @a: Pointer to stack A.
 * @b: Pointer to stack B.
 * Description:
 * - Calculates the most efficient rotation type (rb, rrb, etc.)
 *   for moving an element from B to A.
 * Return: Rotation type as an integer or enum.
 */
int rotate_type_ba(t_stack *a, t_stack *b)
{
    int min_index;
    int max_index;
    int target_index;

    target_index = find_optimal_rotation(b, a);
    min_index = find_min_index(b);
    max_index = find_max_index(b);

    if (target_index < (b->size / 2))
        return (ROTATE_RB);
    else if (target_index >= (b->size / 2))
        return (ROTATE_RRB);
    return (ROTATE_DEFAULT); // Default fallback
}

/**
 * ft_case_rrarrb - Handles combined rotations for optimal placement.
 * @a: Pointer to stack A.
 * @b: Pointer to stack B.
 */
void ft_case_rrarrb(t_stack *a, t_stack *b)
{
    while (a->top && b->top)
    {
        if (rotate_type_ab(a, b) == ROTATE_RA && rotate_type_ba(a, b) == ROTATE_RB)
        {
            rr(a, b);
        }
        else if (rotate_type_ab(a, b) == ROTATE_RRA && rotate_type_ba(a, b) == ROTATE_RRB)
        {
            rrr(a, b);
        }
        else
        {
            if (rotate_type_ab(a, b) == ROTATE_RA)
                ra(a);
            else if (rotate_type_ab(a, b) == ROTATE_RRA)
                rra(a);
            if (rotate_type_ba(a, b) == ROTATE_RB)
                rb(b);
            else if (rotate_type_ba(a, b) == ROTATE_RRB)
                rrb(b);
        }
    }
}
