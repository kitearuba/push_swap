/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:41:10 by chrrodri          #+#    #+#             */
/*   Updated: 2024/12/31 01:19:00 by chrrodri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/*                               Includes                                     */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <stddef.h>
# include "stack.h"
# include "../libft/include/libft.h"

# define STDERR 2

/* ************************************************************************** */
/*                           Function Prototypes                              */
/* ************************************************************************** */

/* Core Functions */
void	push_swap(t_stack *a, t_stack *b);
int		parse_arguments(int argc, char **argv, t_stack *a);

/* Sorting Algorithms */
void	sort_small(t_stack *a, t_stack *b);
void	sort_medium(t_stack *a, t_stack *b);
void	sort_large(t_stack *a, t_stack *b); /* Turkish Sort */

/* Error Handling */
void	handle_error(const char *error_message, t_stack *a, t_stack *b);
void	fatal_error(const char *msg, const char *detail);

/* Helper Functions */
int		is_sorted(t_stack *a);
int		has_duplicates(t_stack *a);
int		find_min(t_stack *stack);
int		find_index(t_stack *stack, int value);
int     find_insert_pos(t_stack *stack, int value);
int     find_min_cost_move(t_stack *a, t_stack *b);
void    apply_min_cost_move(t_stack **a, t_stack **b);
void	move_to_top(t_stack *a, int index); /* Added based on usage */
void	push_smallest_to_b(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
int		has_values_in_range(t_stack *stack, int start, int end);
size_t  list_size(t_stack *stack);
void    apply_min_cost_move(t_stack **a, t_stack **b);

int		is_number(const char *str);
int		has_duplicates(t_stack *a);

#endif // PUSH_SWAP_H
