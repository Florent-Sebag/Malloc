/*
** push_list.c for push in /home/benama_m/PSU_TEK2/PSU_2016_malloc
** 
** Made by benama_m
** Login   <mahdi.benamar@epitech.eu>
** 
** Started on  Wed Feb  8 17:13:43 2017 benama_m
** Last update Sun Feb 12 17:55:31 2017 benama_m
*/

#include "malloc.h"

int             push_back_free(t_free *data)
{
  t_free        *tmp;

  if (g_free == NULL || data == NULL)
    return (-1);
  if (g_free->size_free == 0 || (g_free->begin == NULL && g_free->end == NULL))
    {
      g_free->begin = data;
      g_free->end = data;
    }
  else
    {
      tmp = g_free->end;
      g_free->end->next = data;
      g_free->end = data;
      g_free->end->prev = tmp;
      g_free->end->next = NULL;
    }
  g_free->size_free += 1;
  return (0);
}

int             put_free_position(t_free *tmp, t_free *free)
{
  tmp->prev->next = free;
  free->prev = tmp->prev;
  free->next = tmp;
  tmp->prev = free;
  g_free->size_free += 1;
  return (0);
}

int             push_front_free(t_free *data)
{
  if (g_free == NULL || data == NULL)
    return (-1);
  if (g_free->size_free == 0)
    {
      g_free->begin = data;
      g_free->end = data;
    }
  else
    {
      data->next = g_free->begin;
      g_free->begin->prev = data;
      data->prev = NULL;
      g_free->begin = data;
    }
  g_free->size_free += 1;
  return (0);
}

int             push_front_block(t_elem *data)
{
  if (g_list == NULL || data == NULL)
    return (-1);
  if (g_list->size_block == 0)
    {
      g_list->head = data;
      g_list->tail = data;
    }
  else
    {
      data->next = g_list->head;
      g_list->head = data;
    }
  g_list->size_block += 1;
  return (0);
}

int             push_back_block(t_elem *data)
{
  t_elem        *tmp;

  if (g_list == NULL || data == NULL)
    return (-1);
  if (g_list->size_block == 0 || (g_list->head == NULL && g_list->tail == NULL))
    {
      g_list->head = data;
      g_list->tail = data;
    }
  else
    {
      tmp = g_list->tail;
      g_list->tail->next = data;
      g_list->tail = data;
      g_list->tail->prev = tmp;
    }
  g_list->size_block += 1;
  return (0);
}
