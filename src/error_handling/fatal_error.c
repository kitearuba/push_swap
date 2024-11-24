/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:05 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/24 20:07:17 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fatal_error(const char *msg, const char *detail)
{
	if (msg)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(msg, 2);
	}
	if (detail)
	{
		ft_putstr_fd(" '", 2);
		ft_putstr_fd(detail, 2);
		ft_putstr_fd("'", 2);
	}
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
