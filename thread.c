/*
** thread.c for thread in /home/benama_m/PSU_TEK2/PSU_2016_malloc
** 
** Made by benama_m
** Login   <mahdi.benamar@epitech.eu>
** 
** Started on  Wed Feb  8 21:20:27 2017 benama_m
** Last update Fri Feb 10 12:05:45 2017 benama_m
*/

#include "malloc.h"
#include <pthread.h>

//changer le nom des putains de variable

static	pthread_mutex_t mutex_t = PTHREAD_MUTEX_INITIALIZER;

void		lock_thread()
{
  if (pthread_mutex_lock(&mutex_t) != 0)
    abort();
}

void		unlock_thread()
{
  if (pthread_mutex_unlock(&mutex_t) != 0)
    abort();
}
