/*
** get_simple_coords.c for RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sun Apr 10 22:46:15 2016 romain samuel
** Last update Sun May 22 21:35:35 2016 benjamin duhieu
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
  if (s->hit.k1 < 0.000001 && s->hit.k2 > 0.000001)
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

int	get_simple_inter_complex(t_rt *s, t_acc *vct, t_acc *eye)
{
  s->hit.simple_inter1.x = eye->x + s->hit.k1 * vct->x;
  s->hit.simple_inter1.y = eye->y + s->hit.k1 * vct->y;
  s->hit.simple_inter1.z = eye->z + s->hit.k1 * vct->z;
  s->hit.simple_inter2.x = eye->x + s->hit.k2 * vct->x;
  s->hit.simple_inter2.y = eye->y + s->hit.k2 * vct->y;
  s->hit.simple_inter2.z = eye->z + s->hit.k2 * vct->z;
  s->hit.simple_inter3.x = eye->x + s->hit.k3 * vct->x;
  s->hit.simple_inter3.y = eye->y + s->hit.k3 * vct->y;
  s->hit.simple_inter3.z = eye->z + s->hit.k3 * vct->z;
  s->hit.simple_inter4.x = eye->x + s->hit.k4 * vct->x;
  s->hit.simple_inter4.y = eye->y + s->hit.k4 * vct->y;
  s->hit.simple_inter4.z = eye->z + s->hit.k4 * vct->z;
  return (0);
}
