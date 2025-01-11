/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:24:08 by chrrodri          #+#    #+#             */
/*   Updated: 2025/01/10 21:24:15 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*two_args(char **argv)
{
    t_stack	*a;
    char	**tmp;
    int		i;
    int		j;

    a = NULL;
    i = 0;
    tmp = ft_split(argv[1],' ');
    while (tmp[i])
    {
        j = parse_strict_atoi(tmp[i]);
        stack_add_back(&a, stack_new(j));
        i++;
    }
    free_2d_array(tmp);
    return (a);
}