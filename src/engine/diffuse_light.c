/*
** diffuse_color.c for RAYTRACER$ in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Apr 11 21:43:19 2016 romain samuel
** Last update Sat Apr 16 16:43:46 2016 romain samuel
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

double		diffuse_light(t_rt *s, t_object *it)
{
  double	a;
  double	len;

  len = sqrt(pow(s->shade.vct.x, 2) + pow(s->shade.vct.y, 2)
	     + pow(s->shade.vct.z, 2));
  s->shade.nvct.x = s->shade.vct.x / len;
  s->shade.nvct.y = s->shade.vct.y / len;
  s->shade.nvct.z = s->shade.vct.z / len;
  len = sqrt(pow(s->hit.norm.x, 2) + pow(s->hit.norm.y, 2)
	     + pow(s->hit.norm.z, 2));
  s->hit.nnorm.x = s->hit.norm.x / len;
  s->hit.nnorm.y = s->hit.norm.y / len;
  s->hit.nnorm.z = s->hit.norm.z / len;
  s->hit.cos_theta = (s->hit.nnorm.x * s->shade.nvct.x * -1)
    + (s->hit.nnorm.y * s->shade.nvct.y * -1)
    + (s->hit.nnorm.z * s->shade.nvct.z * -1);
  if ((it->type == 4 || s->hit.limited == 1) && s->hit.cos_theta < 0.00001)
    return (second_norm_brightness(s));
  if (s->hit.cos_theta < 0.0001)
    a = 0.0;
  else
    a = s->hit.cos_theta;
  return (a);
}
