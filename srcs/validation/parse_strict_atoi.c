/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_strict_atoi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:07:41 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/04 21:09:27 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Converts a string to an integer with strict validation.
 * Replaces: ft_atoi2
 */

static void skip_whitespace(const char **str)
{
    while (**str == ' ' || **str == '\t' || **str == '\n' || **str == '\f'
           || **str == '\v' || **str == '\r')
        (*str)++;
}

static int handle_sign(const char **str)
{
    if (**str == '-' || **str == '+')
        return (*((*str)++) == '-') ? -1 : 1;
    return (1);
}

int parse_strict_atoi(const char *str)
{
    long long result;
    int sign;

    result = 0;
    skip_whitespace(&str);
    sign = handle_sign(&str);
    if (!*str)
        handle_error("Invalid number: empty or missing digits", NULL, NULL);
    while (*str && ft_isdigit(*str))
    {
        result = result * 10 + (*str - '0');
        if ((sign * result) > MAX_INT || (sign * result) < MIN_INT)
            handle_error("Number out of range", NULL, NULL);
        str++;
    }
    if (*str)
        handle_error("Invalid character in number", NULL, NULL);
    return ((int)(sign * result));
}
