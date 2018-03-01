/*
** malloc.h for malloc in /home/benama_m/PSU_TEK2/PSU_2016_malloc
** 
** Made by benama_m
** Login   <mahdi.benamar@epitech.eu>
** 
** Started on  Fri Jan 27 11:43:23 2017 benama_m
** Last update Sun Feb 12 18:34:24 2017 benama_m
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dlfcn.h>
#include <limits.h>
#include <string.h>

typedef struct          s_elem
{
  void                  *data;
  size_t		size;
  int			free;
  struct s_elem         *next;
  struct s_elem         *prev;
}                       t_elem;

typedef struct          s_free
{
  void                  *data;
  size_t		size;
  int			free;
  struct s_free         *next;
  struct s_free         *prev;
}                       t_free;

typedef struct          s_list
{
  int                   size_block;
  t_elem                *head;
  t_elem                *tail;
}                      t_list;

typedef struct		s_list_free
{
  int                   size_free;
  t_free		*begin;
  t_free		*end;
}			t_list_free;

#define STRUCT_SIZE sizeof(t_elem);
extern t_list_free	*g_free;
extern t_list           *g_list;

void			my_putchar(char c);
void			my_putstr(char *str);

void			my_free(void *ptr);
size_t			for_alignment(size_t size);
int			check_nbr_page(size_t size);
size_t			for_alignment(size_t);
int			check_nbr_page(size_t size);
t_list			*find_free_block(t_list*, size_t);
void			split_this(t_list *list, size_t);
void			split_first(t_list *list, size_t);

int			push_back_block(t_elem *data);
int			push_back_free(t_free *data);
t_free			*find_block_free(size_t size);
t_elem		        *add_block(size_t size);
t_elem		        *first_block(size_t size);
t_elem			*split_free(t_free *free, size_t size);
int			pos_to_remove(t_free *free);
int			remove_free(t_free *freeg);
int			remove_block(t_elem *pos);
void			show_list();
void			show_free_list();
void			init_list();
int			put_elem_before(t_free* free, t_elem *tmp);
int			push_front_free(t_free *free);
int			push_front_block(t_elem *free);
int			put_free_position(t_free *tmp, t_free *free);
int             	ascending_free(t_free *free);
int			check_fusion(t_free *free);

t_free			*fusion_free_before(t_free *free, t_free*g);
t_free			*fusion_free_after(t_free *free, t_free*);
void			show_list_inversly();
void			show_free_list_inversly();

int			check_pagesize();

void			lock_thread();
void			unlock_thread();

void			put_nbr(int nbr);
void			*my_memset(void *dest, int src, size_t n);

void			my_free(void *ptr);
void			*m_malloc(size_t size);
void			*my_realloc(void *ptr, size_t size);
void			*my_calloc(size_t l, size_t j);

void			free(void *ptr);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			*calloc(size_t l, size_t j);

t_elem			*new_elem(void *ptr, size_t size);
t_free			*new_free(t_elem *elem, size_t page_size);
void			*my_first_malloc(size_t size);
void			*my_malloc(size_t size);
void			put_nbr_hexa(unsigned long ko);
void			show_alloc_mem();
void			free_pagesize();
#endif
