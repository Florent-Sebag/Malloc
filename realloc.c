/*
** realloc.c for realloc in /home/benama_m/PSU_TEK2/PSU_2016_malloc
** 
** Made by benama_m
** Login   <mahdi.benamar@epitech.eu>
** 
** Started on  Fri Feb 10 15:57:39 2017 benama_m
** Last update Sun Feb 12 17:56:00 2017 benama_m
*/

#include "malloc.h"

void            *realloc(void *ptr, size_t size)
{
  t_elem        *elem;
  void          *tmp;

  if (ptr == NULL && size != 0)
    return(malloc(size));
  if (ptr && size == 0)
    {
      free(ptr);
      return (NULL);
    }
  elem = ptr - STRUCT_SIZE;
  if (size < elem->size)
      return (elem->data);
  if ((tmp = malloc(size)) == NULL)
    return (NULL);
  memcpy(tmp, elem->data, elem->size);
  free(elem->data);
  return (tmp);
}

void		*calloc(size_t count, size_t size)
{
  char		*mem;

  if ((mem = malloc(count * size)) == NULL)
    return (NULL);
  my_memset(mem, 0, count * size);
  return (mem);
}

t_elem		*new_elem(void *ptr, size_t size)
{
  t_elem	*elem;

  elem = (void*)ptr;
  elem->size = size;
  ptr = ptr + STRUCT_SIZE;
  elem->data = ptr;
  elem->free = 0;
  elem->next = NULL;
  elem->prev = NULL;
  return (elem);
}

t_free		*new_free(t_elem *elem, size_t page_size)
{
  t_free	*free;

  free = (void*)elem->data + elem->size;
  free->data = (void*)elem->data + elem->size + STRUCT_SIZE;
  free->free = 1;
  free->size = page_size - elem->size - 2 * STRUCT_SIZE;
  free->next = NULL;
  free->prev = NULL;
  return (free);
}
