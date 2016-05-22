/*
** diffuse_color.c for RAYTRACER$ in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Apr 11 21:43:19 2016 romain samuel
** Last update Sat May 21 02:00:06 2016 romain samuel
*/

#include "raytracer.h"

double		second_norm_brightness(t_rt *s)
{
  double	a;

  s->hit.nnorm.x = - s->hit.nnorm.x;
  s->hit.nnorm.y = - s->hit.nnorm.y;
  s->hit.nnorm.z = - s->hit.nnorm.z;
  s->hit.cos_theta = (s->hit.nnorm.x * s->shade.nvct.x * -1)
    + (s->hit.nnorm.y * s->shade.nvct.y * -1)
    + (s->hit.nnorm.z * s->shade.nvct.z * -1);
  if (s->hit.cos_theta < 0.0001)
    a = 0.0;
  else
    a = s->hit.cos_theta;
  return (a);
}

double		diffuse_light(t_rt *s)
{
  double	a;

  s->hit.cos_theta = (s->hit.nnorm.x * s->shade.nvct.x * -1)
    + (s->hit.nnorm.y * s->shade.nvct.y * -1)
    + (s->hit.nnorm.z * s->shade.nvct.z * -1);
  if (s->hit.cos_theta < 0.0001)
    a = 0.0;
  else
    a = s->hit.cos_theta;
  return (a);
}
