/*
** update_real_hit_list.c for RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr 19 15:11:57 2016 romain samuel
** Last update Sat May  7 19:01:11 2016 bougon_p
*/

#include "raytracer.h"

int		update_real_hit_list(t_rt *s)
{
  t_object	*it;

  it = s->obj_hit;
  while (it != NULL && it->real == 1)
    it = it->next;
  if (it == NULL)
    return (1);
  else
    it->real = 1;
  return (0);
}

int		delete_false_hit_objects(t_rt *s)
{
  t_object	*it;

  it = s->obj_hit;
  if (s->obj_hit->next == NULL)
    return (0);
  while (it->next != NULL && it->next->next != NULL)
    it = it->next;
  while (it->next->real == 0)
    {
      bunny_free(it->next);
      it->next = NULL;
      it = it->prev;
    }
  return (0);
}
