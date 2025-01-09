/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_strict_atoi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:07:41 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/04 21:09:27 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void skip_whitespace(const char **str)
{
    while (**str == ' ' || **str == '\t' || **str == '\n' || **str == '\f'
           || **str == '\v' || **str == '\r')
        (*str)++;
}

static int handle_sign(const char **str)
{
    int sign;

    sign = 1;
    if (**str == '-' || **str == '+')
    {
        if (**str == '-')
            sign = -1;
        (*str)++;
    }
    return (sign);
}

int parse_strict_atoi(const char *str)
{
    long long result;
    int sign;

    result = 0;
    skip_whitespace(&str);
    sign = handle_sign(&str);
    while (*str == 0)
        str++;
    if (!*str)
        handle_error(NULL, NULL);
    while (*str && ft_isdigit(*str))
    {
        result = result * 10 + (*str - '0');
        if ((sign * result) > MAX_INT || (sign * result) < MIN_INT)
            handle_error(NULL, NULL);
        str++;
    }
    if (*str)
        handle_error(NULL, NULL);
    return ((int)(sign * result));
}
