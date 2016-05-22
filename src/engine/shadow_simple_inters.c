/*
** shadow_simple_inters.c for RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sun Apr 17 11:55:00 2016 romain samuel
** Last update Sun May 22 17:49:42 2016 benjamin duhieu
*/

#include "raytracer.h"

double		shadow_simple_inter_plan(t_rt *s,
					 t_acc *vct,
					 t_acc *eye,
					 double k)
{
  s->shade.shadow.simple_inter1.x = eye->x + k * vct->x;
  s->shade.shadow.simple_inter1.y = eye->y + k * vct->y;
  s->shade.shadow.simple_inter1.z = eye->z + k * vct->z;
  return (k);
}

double		shadow_simple_inters(t_rt *s,
				     t_acc *vct,
				     t_acc *eye,
				     double k[2])
{
  double	tmp;

  if (k[0] < 0.000001 && k[1] < 0.000001)
    return (-1);
  if (k[0] < s->hit.k1 && k[1] > 0.000001)
    {
      tmp = k[1];
      k[1] = k[0];
      k[0] = tmp;
    }
  if (k[0] < 0.000001 && k[1] > 0.000001)
    {
      tmp = k[1];
      k[1] = k[0];
      k[0] = tmp;
    }
  s->shade.shadow.simple_inter1.x = eye->x + k[0] * vct->x;
  s->shade.shadow.simple_inter1.y = eye->y + k[0] * vct->y;
  s->shade.shadow.simple_inter1.z = eye->z + k[0] * vct->z;
  s->shade.shadow.simple_inter2.x = eye->x + k[1] * vct->x;
  s->shade.shadow.simple_inter2.y = eye->y + k[1] * vct->y;
  s->shade.shadow.simple_inter2.z = eye->z + k[1] * vct->z;
  return (return_k(k));
}
