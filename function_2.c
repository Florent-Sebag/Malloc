/*
** function_2.c for function in /home/benama_m/PSU_TEK2/PSU_2016_malloc
** 
** Made by benama_m
** Login   <mahdi.benamar@epitech.eu>
** 
** Started on  Fri Feb 10 15:52:00 2017 benama_m
** Last update Sun Feb 12 17:44:12 2017 benama_m
*/

#include "malloc.h"

void		put_nbr_hexa(unsigned long nbr)
{
  int		tok;
  char		hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
			   '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

  tok = 0;
  tok = nbr % 16;
  nbr = nbr / 16;
  if (nbr != 0)
    put_nbr_hexa(nbr);
  my_putchar(hex[tok]);
}

void		put_nbr(int nbr)
{
  if (nbr >= 10)
    {
      put_nbr(nbr /  10);
      put_nbr(nbr % 10);
    }
  if (nbr < 10)
    {
      my_putchar(nbr + '0');
    }
}

void		*my_memset(void *dest, int src, size_t n)
{
  size_t	i;

  i = 0;
  while (i < n )
    {
      ((char *)dest)[i] = src;
      i += 1;
    }
  return (dest);
}

void		init_list()
{
  g_list = sbrk(sizeof(t_list));
  g_list->size_block = 0;
  g_list->head = 0;
  g_list->tail = 0;
  g_free = sbrk(sizeof(t_list_free));
  g_free->begin = 0;
  g_free->end = 0;
  g_free->size_free = 0;
}


void		show_alloc_mem()
{
  t_elem	*elem;
  void		*brea_k;

  my_putstr("break : ");
  brea_k = sbrk(0);
  my_putstr("0x");
  put_nbr_hexa((unsigned long)brea_k);
  my_putchar('\n');
  elem = g_list->head;
  while (elem)
    {
      my_putstr("0x");
      put_nbr_hexa((unsigned long)(void*)elem);
      my_putstr(" - ");
      my_putstr("0x");
      put_nbr_hexa((unsigned long)elem + elem->size);
      my_putstr(" : ");
      put_nbr(elem->size);
      my_putstr(" bytes\n");
      elem = elem->next;
    }
}
