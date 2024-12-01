/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_large.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:15:04 by chrrodri          #+#    #+#             */
/*   Updated: 2024/11/27 22:14:37 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_chunk(t_list *chunk)
{
    while (chunk)
    {
        ft_printf("%d ", *(int *)chunk->content);
        chunk = chunk->next;
    }
    ft_printf("\n");
}

t_list	**divide_into_chunks(t_stack *a, int divisor)
{
    t_list	**chunks;
    int		chunk_size;
    int		chunk_count;
    int		i;
    int		j;
    t_list	*current;

    if (!a || divisor <= 0)
        return (NULL);

    chunk_size = a->size / divisor;
    if (chunk_size < 1)
        chunk_size = 1;

    chunk_count = (a->size + chunk_size - 1) / chunk_size;

    chunks = malloc(sizeof(t_list *) * chunk_count);
    if (!chunks)
        return (NULL);

    current = a->top;
    i = 0;
    while (i < chunk_count)
    {
        chunks[i] = NULL;
        j = 0;
        while (j < chunk_size && current)
        {
            ft_lstadd_back(&chunks[i], ft_lstnew(current->content));
            current = current->next;
            j++;
        }
        ft_printf("Chunk %d:\n", i + 1);
        print_chunk(chunks[i]);
        i++;
    }
    return (chunks);
}

void	free_chunks(t_list **chunks, int chunk_count)
{
    int i;

    if (!chunks)
        return ;

    i = 0;
    while (i < chunk_count)
    {
        ft_lstclear(&chunks[i], free);
        i++;
    }
    free(chunks);
}

void	sort_and_push_chunks(t_list **chunks, int chunk_count, t_stack *a, t_stack *b)
{
    int	i;

    i = 0;
    while (i < chunk_count)
    {
        ft_printf("Before sorting chunk %d:\n", i + 1);
        print_chunk(chunks[i]);

        if (ft_lstsize(chunks[i]) <= 5)
            sort_small(a, b);
        else if (ft_lstsize(chunks[i]) <= 20)
            sort_medium(a, b);

        ft_printf("After sorting chunk %d:\n", i + 1);
        print_chunk(chunks[i]);
        i++;
    }
}

void	sort_medium_large(t_stack *a, t_stack *b)
{
    int		divisor;
    t_list	**chunks;
    int		chunk_count;

    if (!a || !a->top || a->size <= 0)
        return ;

    if (a->size <= 50)
        divisor = 5;
    else
        divisor = 10;

    chunks = divide_into_chunks(a, divisor);
    if (!chunks)
        return ;

    chunk_count = (a->size + (a->size / divisor) - 1) / (a->size / divisor);
    sort_and_push_chunks(chunks, chunk_count, a, b);

    free_chunks(chunks, chunk_count);
}
