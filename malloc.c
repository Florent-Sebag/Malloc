/*
** malloc.c for malloc in /home/benama_m/PSU_TEK2/PSU_2016_malloc
** 
** Made by benama_m
** Login   <mahdi.benamar@epitech.eu>
** 
** Started on  Fri Feb  3 15:12:31 2017 benama_m
** Last update Sun Feb 12 17:52:05 2017 benama_m
*/

#include "malloc.h"

t_list		*g_list = NULL;
t_list_free	*g_free = NULL;

t_elem		*first_block(size_t size)
{
  t_elem	*elem;
  t_free	*free;
  void		*ptr;
  size_t	page_size;
  
  ptr = sbrk(0);
  page_size = getpagesize() * check_nbr_page(for_alignment(size)) + STRUCT_SIZE;
  if ((sbrk(page_size) == (void*) - 1) || size >= LONG_MAX)
    return (NULL);
  elem = new_elem(ptr, size);
  if (elem->size + sizeof(t_elem) == page_size)
    {
      g_list = NULL;
      return (elem);
    }
  free = new_free(elem, page_size);
  push_back_free(free);
  return (elem);
}

t_elem		*split_free(t_free *free, size_t size)
{
  t_elem	*new;
  t_free	*fr_new;
  int		operation;

  operation = free->size - size - STRUCT_SIZE;
  new = (void*)free->data - STRUCT_SIZE;
  new->data = (void*)free->data;
  new->free = 0;
  new->size = size;
  if (new->size + sizeof(t_elem) == free->size)
    {
      remove_free(free);
      return (new);
    }
  fr_new = (void*)new->data + new->size;
  fr_new->data = (void*)new->data + new->size + STRUCT_SIZE;
  fr_new->size = operation;
  fr_new->free = 1;
  fr_new->prev = NULL;
  fr_new->next = NULL;
  remove_free(free);
  ascending_free(fr_new);
  return (new);
}

void		*malloc(size_t size)
{
  size_t	page_size;

  if (g_list == NULL)
    return (my_first_malloc(for_alignment(size)));
  else
    {
      if (find_block_free(for_alignment(size)) == NULL)
      	{
	  page_size = getpagesize() * check_nbr_page(for_alignment(size)) + sizeof(t_elem);
      	  if ((sbrk(page_size) == (void *) - 1) || size >= LONG_MAX)
	    return (NULL);
	  g_free->end->size = g_free->end->size + page_size - sizeof(t_elem);
	}
      return (my_malloc(for_alignment(size)));
    }
}

void		*my_first_malloc(size_t size)
{
  t_elem	*elem;

  init_list();
  elem = first_block(size);
  push_back_block(elem);
  return (elem->data);
}

void		*my_malloc(size_t size)
{
  t_free	*free;
  t_elem	*elem;

  free = find_block_free(size);
  elem = split_free(free, size);
  push_back_block(elem);
  return(elem->data);
}
