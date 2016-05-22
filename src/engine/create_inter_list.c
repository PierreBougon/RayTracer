/*
** create_inter_list.c for RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sat May 14 17:31:51 2016 romain samuel
** Last update Sun May 22 21:33:13 2016 benjamin duhieu
*/

#include "raytracer.h"

t_inter		*create_inter_list()
{
  t_inter	*root;

  if ((root = bunny_malloc(sizeof(t_inter))) == NULL)
    return (NULL);
  root->prev = NULL;
  root->next = NULL;
  return (root);
}

t_inter		*add_inter_elem(t_inter *elem)
{
  t_inter	*new;

  if ((new = bunny_malloc(sizeof(t_inter))) == NULL)
    return (NULL);
  new->prev = elem;
  if (elem->next != NULL)
    {
      new->next = elem->next;
      elem->next->prev = new;
    }
  else
    new->next = NULL;
  elem->next = new;
  return (new);
}

t_inter		*delete_inter_elem(t_inter *elem)
{
  t_inter	*previous;
  t_inter	*next;

  if (elem == NULL)
    return (NULL);
  if (elem->prev == NULL)
    return (NULL);
  if (elem->next == NULL)
    {
      previous = elem->prev;
      previous->next = NULL;
      bunny_free(elem);
      return (previous);
    }
  previous = elem->prev;
  next = elem->next;
  previous->next = next;
  next->prev = previous;
  bunny_free(elem);
  return (previous);
}
