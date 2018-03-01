/*
** function.c for function in /home/benama_m/PSU_TEK2/PSU_2016_malloc
** 
** Made by benama_m
** Login   <mahdi.benamar@epitech.eu>
** 
** Started on  Wed Feb  1 14:27:36 2017 benama_m
** Last update Sun Feb 12 17:54:47 2017 benama_m
*/

#include "malloc.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i += 1;
    }
}

int		check_nbr_page(size_t size)
{
  size_t	check;
  int		i;
  
  check = getpagesize();
  if (size < check)
    return (1);
  else
    {
      i = 1;
      while (size > check)
	{
	  size -= check;
	  i += 1;
	}
      return (i);
    }
}

size_t		for_alignment(size_t size)
{
  if (size % 4 == 0)
    return (size);
  while ((size % 4 != 0))
    size += 1;
  return (size);
}

t_free		*find_block_free(size_t size)
{
  t_free	*tmp;

  tmp = g_free->begin;
  if (tmp == NULL)
    return (NULL);
  while (tmp)
    {
      if (tmp->size > size + sizeof(t_elem))
	  return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}
