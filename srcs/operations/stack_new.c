/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:32:55 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/23 16:56:25 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_list *stack_new(int value)
{
    int     *content;
    t_list  *node;

    content = malloc(sizeof(int));
    if (!content)
        fatal_error("Memory allocation failed", NULL);
    *content = value;

    node = ft_lstnew(content);
    if (!node)
    {
        free(content);
        fatal_error("Memory allocation failed", NULL);
    }
    return (node);
}
