/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:41:10 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/26 22:09:12 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <stddef.h>
# include "stack.h"
# include "utils.h"
# include "../libft/include/libft.h"

/* Core Functions */
void	push_swap(t_stack *a, t_stack *b);
int		parse_arguments(int argc, char **argv, t_stack *a);
int		is_number(const char *str);
int		has_duplicates(t_stack *a);
void	free_stack(t_stack *stack);
void	free_all_stacks(t_stack *a, t_stack *b);

/* Error Handling */
void	clean_all(t_stack *a, t_stack *b);
int		error_handle(const char *error_message, t_stack *a, t_stack *b);
void	fatal_error(const char *msg, const char *detail);
void	free_on_error(t_stack *a, t_stack *b, const char *error_message);

/* Sorting Functions */
void	sort_small(t_stack *a, t_stack *b);
void	sort_medium(t_stack *a, t_stack *b);
void	sort_large(t_stack *a, t_stack *b);

// sort_helper.c
int		calculate_chunk_size(int size);
int		find_next_target(t_stack *a, int chunk_size, int index);
void	move_to_top(t_stack *a, int value);
void	push_min_to_b(t_stack *a, t_stack *b);

// find_target_index.c
int find_index(t_stack *stack, int value);
int find_min(t_stack *stack);

/* Utility Functions */
int		is_sorted(t_stack *a);

#endif // PUSH_SWAP_H
