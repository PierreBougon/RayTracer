/*
** get_simple_coords.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sun Apr 10 22:46:15 2016 romain samuel
** Last update Tue Apr 12 23:12:53 2016 romain samuel
*/

#include "raytracer.h"

int		get_simple_inter(t_rt *s, t_acc *vct, t_acc *eye)
{
  double	tmp;

  if (s->hit.k1 < 0.000001 && s->hit.k2 < 0.000001)
    return (-1);
  if (s->hit.k2 < s->hit.k1 && s->hit.k2 > 0.000001)
    {
      tmp = s->hit.k2;
      s->hit.k2 = s->hit.k1;
      s->hit.k1 = tmp;
    }
  s->hit.simple_inter1.x = eye->x + s->hit.k1 * vct->x;
  s->hit.simple_inter1.y = eye->y + s->hit.k1 * vct->y;
  s->hit.simple_inter1.z = eye->z + s->hit.k1 * vct->z;
  s->hit.simple_inter2.x = eye->x + s->hit.k2 * vct->x;
  s->hit.simple_inter2.y = eye->y + s->hit.k2 * vct->y;
  s->hit.simple_inter2.z = eye->z + s->hit.k2 * vct->z;
  return (0);
}
