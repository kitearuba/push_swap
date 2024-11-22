#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "utils.h"

// Sorting Functions
void    push_swap(t_stack *a, t_stack *b);
void    sort_small(t_stack *a);
void    sort_large(t_stack *a, t_stack *b);

#endif // PUSH_SWAP_H
