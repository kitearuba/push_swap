/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:51:46 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/24 15:22:09 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "push_swap.h"

// Utility Functions
void    error_exit(const char *message);
int	is_sorted(t_stack *a);
int	parse_arguments(int argc, char **argv, t_stack *a);
int     is_number(const char *str);


#endif // UTILS_H
