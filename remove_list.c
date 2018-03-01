/*
** remove_list.c for remove in /home/benama_m/PSU_TEK2/PSU_2016_malloc
** 
** Made by benama_m
** Login   <mahdi.benamar@epitech.eu>
** 
** Started on  Wed Feb  8 17:15:43 2017 benama_m
** Last update Sun Feb 12 17:55:48 2017 benama_m
*/

#include "malloc.h"

int             remove_free(t_free *free)
{
  if (free == g_free->begin && free == g_free->end)
    {
      g_free->begin = NULL;
      g_free->end = NULL;
      g_free->size_free = 0;
      return (0);
    }
  if (free == g_free->begin)
    {
      g_free->begin = g_free->begin->next;
      g_free->size_free = g_free->size_free - 1;
      return (0);
    }
  if (free == g_free->end)
    {
      free = free->prev;
      free->next = NULL;
      g_free->end = free;
      g_free->size_free = g_free->size_free - 1;
      return (0);
    }
  free->prev->next = free->next;
  free->next->prev = free->prev;
  g_free->size_free = g_free->size_free - 1;
  return (0);
}

int             remove_block(t_elem *elem)
{
  if (elem == g_list->head && elem == g_list->tail)
    {
      g_list->head = NULL;
      g_list->tail = NULL;
      g_list->size_block = 0;
      return (0);
    }
  if (elem == g_list->head)
    {
      g_list->head = g_list->head->next;
      g_list->size_block = g_list->size_block - 1;
      return (0);
    }
  if (elem == g_list->tail)
    {
      g_list->tail = elem->prev;
      elem->prev->next = elem->next;
      g_list->size_block = g_list->size_block - 1;
      return (0);
    }
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  g_list->size_block = g_list->size_block - 1;
  return (0);
}
