/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:05 by chrrodri          #+#    #+#             */
/*   Updated: 2024/12/31 01:07:17 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Specialized error handling for fatal errors.
 * No stack cleanup, only prints an error message using ft_printf_fd and exits.
 */
void fatal_error(const char *msg, const char *detail)
{
	if (msg && detail)
		ft_printf_fd(STDERR, "Error: %s '%s'\n", msg, detail);
	else if (msg)
		ft_printf_fd(STDERR, "Error: %s\n", msg);
	else
		ft_printf_fd(STDERR, "Error\n");
	exit(EXIT_FAILURE);
}
