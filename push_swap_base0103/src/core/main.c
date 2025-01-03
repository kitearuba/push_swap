/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:36 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/25 18:33:21 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack *arg2_split(**argv)
{
    t_stack *a;
    char    **tmp;
    char	**ptr_tmp;

    a = NULL;
    ptr_tmp = tmp;
    tmp = ft_split(argv[1], ' ');
    while (*ptr)
    {
        ft_add_back(&a, ft_stack_new(ft_atoi(*ptr)));
        ptr++;
    }
    ft_freestr(tmp);
    free(tmp);
    return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	//t_stack	*b;

    if (argc < 2)
        return (0);
    else if (argc == 2)
        a = arg2_split(argv);
    if (argc > 2)

	a = create_stack();
	if (!a)
		fatal_error("Failed to create stack A", NULL);
	//b = create_stack();
	//if (!b)
	//	handle_error("Failed to create stack B", a, NULL);
	if (parse_arguments(argc - 1, argv + 1, a) == -1)
		handle_error("Invalid input", a, b);
	push_swap(a, b);
	free_all_stacks(a, b);
	return (0);
}
