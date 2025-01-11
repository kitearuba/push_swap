/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:41:10 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/05 21:30:17 by chrrodri         ###   ########.fr       */
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
/*                          Macros for Rotation Types                         */
/* ************************************************************************** */

# define STDERR 2
# define MAX_INT 2147483647
# define MIN_INT -2147483648

// Rotation Types
# define ROTATE_RA       0
# define ROTATE_RRA      1
# define ROTATE_RB       2
# define ROTATE_RRB      3
# define ROTATE_DEFAULT -1

/* ************************************************************************** */
/*                           Function Prototypes                              */
/* ************************************************************************** */

/* Validation */
void    parse_arguments(int argc, char **argv, t_stack **stack);
t_stack	*two_args(char **argv);
int     is_number(const char *str);
int     has_duplicates(t_stack *a);
int     is_sorted(t_stack *stack);
int     parse_strict_atoi(const char *str);
//void	ft_add_back(t_stack **stack, t_stack *stack_new);

/* Utils */
void	free_2d_array(char **arr);
void	stack_free(t_stack **stack);
int     rotate_type_ab(t_stack *a, t_stack *b);
int     rotate_type_ba(t_stack *a, t_stack *b);

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


int	       ft_min(t_stack *a);
int        ft_max(t_stack *a);
int        find_index(t_stack *a, int nbr);
int        find_place_b(t_stack *b, int nbr_push);
int        find_place_a(t_stack *a, int nbr_push);

/* Sorting */
void    sort_three(t_stack **stack);
void	sort_small(t_stack **a);
void	sort_big(t_stack **a);
void    sort_stack(t_stack *a);
int     is_min_or_max(t_stack *a);
int     find_optimal_rotation(t_stack *a, t_stack *b);

/* Error Handling */
void    handle_error(t_stack *a, t_stack *b);
void	fatal_error(void);

/* Helper Functions */
int		find_min(t_stack *stack);
int		find_insert_pos(t_stack *stack, int value);

#endif // PUSH_SWAP_H-
