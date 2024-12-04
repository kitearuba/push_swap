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

t_list	**divide_into_chunks(t_stack *a, int chunk_size, int chunk_count)
{
	t_list	**chunks;
	int		i;
	int		j;

	chunks = malloc(sizeof(t_list *) * chunk_count);
	if (!chunks)
		return (NULL);
	i = 0;
	while (i < chunk_count)
	{
		chunks[i] = NULL;
        j = 0;
        while (j < chunk_size && a->top)
		{
			ft_lstadd_back(&chunks[i], ft_lstnew(a->top->content));
			a->top = a->top->next;
            j++;
		}
		ft_printf("Chunk %d:\n", i + 1);
		print_chunk(chunks[i]);
		i++;
	}
	return (chunks);
}

void	sort_chunk(t_list **chunk)
{
	t_list	*ptr1;
	t_list	*ptr2;
    int		temp;
    int		swap;

    if (!*chunk)
      return ;
    swap = 1;
    while (swap)
    {
      swap = 0;
      ptr1 = *chunk;
      while (ptr1 && ptr1->next)
      {
        ptr2 = ptr1->next;
        if (*(int *)ptr1->content > *(int *)ptr2->content)
        {
          temp = *(int *)ptr1->content;
          *(int *)ptr1->content = *(int *)ptr2->content;
          *(int *)ptr2->content = temp;
          swap = 1;
        }
        ptr1 = ptr1->next;
	  }
    }
}

t_list	*merge_chunks(t_list *chunk1, t_list *chunk2)
{
  t_list	*merged;
  t_list	**tail;

  merged = NULL;
  tail = &merged;
  while (chunk1 && chunk2)
  {
    if (*(int *)chunk1->content < *(int *)chunk2->content)
    {
      ft_lstadd_back(tail, ft_lstnew(chunk1->content));
      chunk1 = chunk1->next;
    }
    else
    {
      ft_lstadd_back(tail, ft_lstnew(chunk2->content));
      chunk2 = chunk2->next;
    }
    tail = &((*tail)->next);
  }
  while (chunk1)
  {
    ft_lstadd_back(tail, ft_lstnew(chunk1->content));
    chunk1 = chunk1->next;
    tail = &((*tail)->next);
  }
  while (chunk2)
  {
    ft_lstadd_back(tail, ft_lstnew(chunk2->content));
    chunk2 = chunk2->next;
    tail = &((*tail)->next);
  }
  return (merged);
}

t_list	*reintegrate_chunks(t_list **chunks, int chunk_count)
{
  int		i;
  int		new_chunck_count;

  while (chunk_count > 1)
  {
    i = 0;
    new_chunck_count = 0;
    while (i < chunk_count)
    {
      if (i + 1 < chunk_count)
      {
        // Merge two chunks and store the result in the first chunk
        chunks[new_chunck_count] = merge_chunks(chunks[i], chunks[i + 1]);
        i+= 2;
      }
      else
      {
         // If there’s an odd number of chunks, keep the last one as is
        chunks[new_chunck_count] = chunks[i];
        i++;
      }
      new_chunck_count++;
    }
    chunk_count = new_chunck_count;
  }
  return (chunks[0]);  // Return the final merged chunk
}

void	sort_medium_large(t_stack *a, t_stack *b)
{
	int		chunk_size;
    int		chunk_count;
	t_list	**chunks;
    t_list	*sorted_list;

    b->size = 0;
	if (!a || !a->top || a->size <= 0)
		return ;
	chunk_size = a->size / 5;
    if (a->size > 50)
      chunk_size = a->size / 10;
    chunk_count = (a->size + chunk_size - 1) / chunk_size;
	chunks = divide_into_chunks(a, chunk_size, chunk_count);
	if (!chunks)
		return ;
	while (chunk_count > 0)
          sort_chunk(&chunks[--chunk_count]);
    sorted_list = reintegrate_chunks(chunks, chunk_count);
    while(sorted_list)
    {
      ft_lstadd_back(&a->top, ft_lstnew(sorted_list->content));
      sorted_list = sorted_list->next;
    }
    free(chunks);
}