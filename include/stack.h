#ifndef STACK_H
# define STACK_H

# include "../libft/include/libft.h"

/* ************************************************************************** */
/*                           Stack Structure                                  */
/* ************************************************************************** */


typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;


/* ************************************************************************** */
/*                           Function Prototypes                              */
/* ************************************************************************** */

/* Stack Management */


t_stack	*create_stack(void);
void	free_stack(t_stack *stack);
void	free_all_stacks(t_stack *a, t_stack *b);

/* Stack Operations */
void	append_stack_node(t_stack **stack, t_stack *stack_new);
t_stack	*create_stack_node(int content);


void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	swap_top_two(t_stack *stack);
void	push_node(t_stack *from, t_stack *to);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

/* Commands */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif // STACK_H
