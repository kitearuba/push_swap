/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2d_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:06:54 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/09 12:06:48 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                          2D Array Memory Cleanup                          */
/* ************************************************************************** */

/**
 * free_2d_array - Frees a dynamically allocated 2D array.
 * @arr: Pointer to the 2D array to free.
 * Description:
 * - Iterates through the array, freeing each individual element.
 * - Frees the array itself and sets its pointer to NULL.
 */
void	free_2d_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}
