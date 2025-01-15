/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:41:10 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/12 16:02:00 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/*                               Includes                                     */
/* ************************************************************************** */

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include "stack.h"
# include "../libft/include/libft.h"

/* ************************************************************************** */
/*                                  Macros                                    */
/* ************************************************************************** */

# define STDERR 2
# define MAX_INT 2147483647
# define MIN_INT -2147483648

/* ************************************************************************** */
/*                           Function Prototypes                              */
/* ************************************************************************** */

/* Validation */
t_stack		*validate_arguments(int argc, char **argv);
int			is_sorted(t_stack *stack);
int			parse_strict_atoi(const char *str);

/* Sorting */
void		sort_stack(t_stack **a);
void		sort_three(t_stack **stack);
void		sort_large(t_stack **stack_a);

/* Error Handling */
void		handle_error(t_stack *a, t_stack *b);
void		fatal_error(void);

/* Utils Sort Large */
int			find_optimal_rotation_ab(t_stack *a, t_stack *b);
int			find_optimal_rotation_ba(t_stack *a, t_stack *b);
t_stack		*get_last_node(t_stack *stack);
int			get_stack_size(t_stack *stack);
int			find_min_value(t_stack *stack);
int			find_max_value(t_stack *stack);
int			find_index_in_stack(t_stack *stack, int target_value);
int			determine_position_in_stack_a(t_stack *stack_a, int number);
int			determine_position_in_stack_b(t_stack *stack_b, int number);
int			calculate_rotations_ab(t_stack *a, t_stack *b, int target_value);
int			calculate_rr_a_and_b(t_stack *a, t_stack *b, int target_value);
int			calculate_rra_and_rb(t_stack *stack_a, t_stack *stack_b, int target_value);
int			calculate_ra_and_rrb(t_stack *stack_a, t_stack *stack_b, int target_value);
int			calculate_rotations_ba(t_stack *a, t_stack *b, int target_value);
int			calculate_rr_b_and_a(t_stack *stack_a, t_stack *stack_b, int target_value);
int			calculate_rrb_and_ra(t_stack *a, t_stack *b, int target_value);
int			calculate_rb_and_rra(t_stack *a, t_stack *b, int target_value);
int			rotate_both_forward(t_stack **a, t_stack **b, int target, char stack_type);
int			rotate_both_reverse(t_stack **a, t_stack **b, int target, char stack_type);
int			rotate_a_reverse_b_forward(t_stack **a, t_stack **b, int target, char stack_type);
int			rotate_a_forward_b_reverse(t_stack **a, t_stack **b, int target, char stack_type);

/* Utils */
void		free_2d_array(char **arr);

#endif /* PUSH_SWAP_H */