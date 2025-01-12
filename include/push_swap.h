/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:41:10 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/12 01:14:00 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/*                               Includes                                     */
/* ************************************************************************** */

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
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
void       validate_arguments(int argc, char **argv, t_stack **stack);
int        is_sorted(t_stack *stack);
int        parse_strict_atoi(const char *str);

/* Sorting */
void    sort_stack(t_stack *a);
void    sort_three(t_stack **stack);
void	sort_small(t_stack **a);
void	sort_large(t_stack **stack_a);

/* Error Handling */
void    handle_error(t_stack *a, t_stack *b);
void	fatal_error(void);

/* Utils Sort Large*/
int	find_optimal_rotation_ab(t_stack *a, t_stack *b);
int	find_optimal_rotation_ba(t_stack *a, t_stack *b);

t_stack	*get_last_node(t_stack *stack);
int	get_stack_size(t_stack *stack);
int	find_min_value(t_stack *stack);
int	find_max_value(t_stack *stack);
int	find_index_in_stack(t_stack *stack, int target_value);
int	determine_position_in_stack_b(t_stack *stack_b, int number);
int	determine_position_in_stack_a(t_stack *stack_a, int number);

int	       ft_min(t_stack *a);
int        ft_max(t_stack *a);
int        find_index(t_stack *a, int nbr);
int        find_place_b(t_stack *b, int nbr_push);
int        find_place_a(t_stack *a, int nbr_push);

/* Utils */
void	free_2d_array(char **arr);

int	    case_rarb(t_stack *a, t_stack *b, int c);
int	    case_rrarrb(t_stack *a, t_stack *b, int c);
int	    case_rrarb(t_stack *a, t_stack *b, int c);
int	    case_rarrb(t_stack *a, t_stack *b, int c);
int     case_rarb_a(t_stack *a, t_stack *b, int c);
int     case_rrarrb_a(t_stack *a, t_stack *b, int c);
int     case_rarrb_a(t_stack *a, t_stack *b, int c);
int	    case_rrarb_a(t_stack *a, t_stack *b, int c);

int	apply_rarb(t_stack **a, t_stack **b, int c, char s);
int	apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
int	apply_rrarb(t_stack **a, t_stack **b, int c, char s);
int	apply_rarrb(t_stack **a, t_stack **b, int c, char s);





int     is_min_or_max(t_stack *a);
//int     find_optimal_rotation(t_stack *a, t_stack *b);

/* Helper Functions */
int		find_min(t_stack *stack);
int		find_insert_pos(t_stack *stack, int value);

#endif // PUSH_SWAP_H-
