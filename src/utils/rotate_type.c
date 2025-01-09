/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:41:10 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/05 21:30:17 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* ************************************************************************** */
/*                      Rotate Type Decision Logic                            */
/* ************************************************************************** */

/**
 * rotate_type_ab - Determines the type of rotation for stack A.
 * @a: Pointer to stack A.
 * @b: Pointer to stack B.
 * Description:
 * - Calculates the most efficient rotation type (ra, rra, etc.)
 *   for moving an element from A to B.
 * Return: Rotation type as an integer or enum.
 */
int	rotate_type_ba(t_stack *a, t_stack *b)
{
    int		i;
    t_stack	*tmp;

    tmp = b;
    i = case_rrarrb_a(a, b, b->nbr);
    while (tmp)
    {
        if (i > case_rarb_a(a, b, tmp->nbr))
            i = case_rarb_a(a, b, tmp->nbr);
        if (i > case_rrarrb_a(a, b, tmp->nbr))
            i = case_rrarrb_a(a, b, tmp->nbr);
        if (i > case_rarrb_a(a, b, tmp->nbr))
            i = case_rarrb_a(a, b, tmp->nbr);
        if (i > case_rrarb_a(a, b, tmp->nbr))
            i = case_rrarb_a(a, b, tmp->nbr);
        tmp = tmp->next;
    }
    return (i);
}

// This function calculate and decides which rotation
// combination is best to use to sort the stack. Of
// course, after rotation there is always one push
// operation is left to do which i embeded to code.
// Function is used during push from A to B.
int	rotate_type_ab(t_stack *a, t_stack *b)
{
    int		i;
    t_stack	*tmp;

    tmp = a;
    i = case_rrarrb(a, b, a->nbr);
    while (tmp)
    {
        if (i > case_rarb(a, b, tmp->nbr))
            i = case_rarb(a, b, tmp->nbr);
        if (i > case_rrarrb(a, b, tmp->nbr))
            i = case_rrarrb(a, b, tmp->nbr);
        if (i > case_rarrb(a, b, tmp->nbr))
            i = case_rarrb(a, b, tmp->nbr);
        if (i > case_rrarb(a, b, tmp->nbr))
            i = case_rrarb(a, b, tmp->nbr);
        tmp = tmp->next;
    }
    return (i);
}
