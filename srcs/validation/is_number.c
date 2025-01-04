/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:15 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/25 18:41:59 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// Checks if the string is a valid number.
int    is_number(const char *str)
{
    if (*str == '-' || *str == '+') // Allow optional '+' or '-' at the start
        str++;
    if (!*str) // Ensure there's at least one digit after the sign
        return (0);
    while (*str)
    {
        if (!ft_isdigit(*str)) // Check if each character is a digit
            return (0);
        str++;
    }
    return (1);
}