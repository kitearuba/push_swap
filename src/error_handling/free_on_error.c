/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_on_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:48:14 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/24 20:09:51 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_on_error(t_stack *a, t_stack *b, const char *error_message)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	fatal_error(error_message, NULL);
}
