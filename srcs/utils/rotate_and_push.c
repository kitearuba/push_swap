/* ************************************************************************** */
/*                      Helper Functions for Turkish Sort                    */
/* ************************************************************************** */


/**
 * rotate_and_push - Rotates stack A to optimize element placement in stack B.
 * @a: Pointer to stack A.
 * @b: Pointer to stack B.
 */
void rotate_and_push(t_stack *a, t_stack *b)
{
	int target_index;

	target_index = find_optimal_rotation(a, b);
	move_to_top(a, target_index);
	pb(a, b);
}