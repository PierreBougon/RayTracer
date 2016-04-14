/*
** specular_light.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr 12 15:55:24 2016 romain samuel
** Last update Wed Apr 13 19:15:37 2016 romain samuel
*/

#include "raytracer.h"

double		specular_light(t_rt *s, t_acc *vision)
{
  double	a;
  double	len;
  t_acc		nvision;

  s->hit.r.x = 2 * s->hit.cos_theta * s->hit.nnorm.x + s->shade.nvct.x;
  s->hit.r.y = 2 * s->hit.cos_theta * s->hit.nnorm.y + s->shade.nvct.y;
  s->hit.r.z = 2 * s->hit.cos_theta * s->hit.nnorm.z + s->shade.nvct.z;
  len = sqrt(pow(vision->x, 2) + pow(vision->y, 2) + pow(vision->z, 2));
  nvision.x = vision->x / len;
  nvision.y = vision->y / len;
  nvision.z = vision->z / len;
  a = (nvision.x * s->hit.r.x)
    + (nvision.y * s->hit.r.y)
    + (nvision.z * s->hit.r.z);
  a = pow(a, 100);
  if (a < 0.0001)
    a = 0.0;
  /*coef = (nvision.x * s->hit.nnorm.x)
    + (nvision.y * s->hit.nnorm.y)
    + (nvision.z * s->hit.nnorm.z);
    get_reflect_vec(s, nvision, coef);*/
  return (a);
}
