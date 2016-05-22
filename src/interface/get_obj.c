/*
** get_obj.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue May 10 14:33:17 2016 romain samuel
** Last update Sat May 21 23:47:42 2016 bougon_p
*/

#include "raytracer.h"

t_object	*get_obj(t_rt *s, int x, int y)
{
  t_object	*it;
  t_acc		vct;

  vct.x = ((double)s->width / 2.0) - (double)x;
  vct.y = ((double)s->height / 2.0) - (double)y;
  vct.z = 1000;
  s->ray.vct = &vct;
  s->ray.eye = s->eye.pos;
  rotation(&s->rotation, s->ray.vct, &s->eye.rot);
  inter_objects(s);
  order_hit_list(s->obj_hit);
  if (s->obj_hit == NULL || s->obj_hit->next == NULL)
    return (NULL);
  it = s->obj;
  while (my_strcmp(s->obj_hit->next->name, it->name) != 0)
    it = it->next;
  return (it);
}
