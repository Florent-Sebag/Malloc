/*
** for_free.c for for_free in /home/benama_m/PSU_TEK2/PSU_2016_malloc
** 
** Made by benama_m
** Login   <mahdi.benamar@epitech.eu>
** 
** Started on  Wed Feb  8 17:17:19 2017 benama_m
** Last update Sun Feb 12 17:54:13 2017 benama_m
*/

#include "malloc.h"

void		free(void *ptr)
{
  t_elem	*tmp;
  t_free	*free;
  
  if (ptr == NULL)
    return;
  tmp = (void*)ptr - STRUCT_SIZE;
  free = (void*)tmp->data - STRUCT_SIZE;
  free->data = (void*)tmp->data;
  free->size = tmp->size;
  free->free = 1;
  remove_block(tmp);
  ascending_free(free);
}

int		ascending_free(t_free *free)
{
  t_free	*tmp;
  
  tmp = g_free->begin;
  while (tmp && free > tmp)
    tmp = tmp->next;
  if (tmp == g_free->begin)
    push_front_free(free);
  else if (free > g_free->end)
    push_back_free(free);
  else if (g_free->size_free == 0)
    push_back_free(free);
  else
    put_free_position(tmp, free);
  if (g_free->size_free > 1)
    check_fusion(free);
  return (0);
}

int		check_fusion(t_free *free)
{
  t_free	*before;
  t_free	*after;

  before = free->prev;
  if (before != NULL)
    {
      if (free == before->data + before->size)
	free = fusion_free_before(before, free);
    }
  after = free->next;
  if (after != NULL)
    {
      if (after == free->data + free->size)
	free = fusion_free_after(after, free);
    }
  return (0);
}

t_free		*fusion_free_before(t_free *before, t_free *free)
{
  size_t	size;

  size = free->size;
  free = before->data - STRUCT_SIZE;
  free->data = before->data;
  free->size = size + before->size + STRUCT_SIZE;
  remove_free(free->next);
  return (free);
}

t_free		*fusion_free_after(t_free *after, t_free *free)
{
  size_t	size;

  size = free->size;
  free->size = size + after->size + STRUCT_SIZE;
  free->free = 1;
  remove_free(after);
  return (free);
}
