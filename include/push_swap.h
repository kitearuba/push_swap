/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:41:10 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/22 12:17:46 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include "stack.h"
#include "utils.h"
#include "../libft/include/libft.h"

// Core Functions
void    push_swap(t_stack *a, t_stack *b);
int     parse_arguments(int argc, char **argv, t_stack *a);

// Sorting Functions
void    sort_small(t_stack *a);
void    sort_medium(t_stack *a, t_stack *b);
void    sort_large(t_stack *a, t_stack *b);

// Utility Functions
int     is_sorted(t_stack *a);

#endif // PUSH_SWAP_H
