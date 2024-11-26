/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:41:10 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/26 19:11:29 by chrrodri         ###   ########.fr       */
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
#include <limits.h>

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
int		find_target_index(t_stack *a, int low, int high);
void	sort_small(t_stack *a, t_stack *b);
void	sort_medium(t_stack *a, t_stack *b);
void	sort_large(t_stack *a, t_stack *b);
int		find_max_index(t_stack *stack);
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);

/* Utility Functions */
int		is_sorted(t_stack *a);

#endif // PUSH_SWAP_H
