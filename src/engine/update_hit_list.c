/*
** update_hit_list.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sun Apr 10 14:03:22 2016 romain samuel
** Last update Mon Apr 11 15:00:45 2016 romain samuel
*/

#include "raytracer.h"

int		update_hit_list(t_rt *s, void *shape, int type, double k)
{
  t_object	*it;

  if (s->hit.k1 > 0.000001 || s->hit.k2 > 0.000001)
    {
      if (s->obj_hit == NULL)
	{
	  if ((s->obj_hit = create_obj_list()) == NULL)
	    return (-1);
	}
      if (add_obj_elem(s->obj_hit) == -1)
	return (-1);
      it = s->obj_hit;
      while (it->next != NULL)
	it = it->next;
      it->datas = shape;
      it->type = type;
      it->k = k;
    }
  return (0);
}
