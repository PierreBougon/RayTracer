/*
** get_norm.c<RAYTRACER> for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sun Apr 10 22:40:50 2016 romain samuel
** Last update Mon May  2 17:21:16 2016 romain samuel
*/

#include "raytracer.h"

void		get_norm_plan(t_rt *s, t_plan *plan)
{
  s->hit.norm.x = 0;
  s->hit.norm.y = 0;
  s->hit.norm.z = -100;
  end_rotation(&s->rotation, &s->hit.norm, &plan->rot);
}

void		get_norm_sphere(t_rt *s)
{
  s->hit.norm.x = s->hit.simple_inter1.x;
  s->hit.norm.y = s->hit.simple_inter1.y;
  s->hit.norm.z = s->hit.simple_inter1.z;
}

void		get_norm_cylinder(t_rt *s, t_cylinder *cylinder)
{
  s->hit.norm.x = s->hit.simple_inter1.x;
  s->hit.norm.y = s->hit.simple_inter1.y;
  s->hit.norm.z = 0;
  end_rotation(&s->rotation, &s->hit.norm, &cylinder->rot);
}

void		get_norm_cone(t_rt *s, t_cone *cone)
{
  s->hit.norm.x = s->hit.simple_inter1.x;
  s->hit.norm.y = s->hit.simple_inter1.y;
  s->hit.norm.z = - 0.1 * s->hit.simple_inter1.z;
  end_rotation(&s->rotation, &s->hit.norm, &cone->rot);
}
